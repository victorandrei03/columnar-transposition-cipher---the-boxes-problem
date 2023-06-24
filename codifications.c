#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>

void selectionSort(char *key, int *order, int columns) {
    char *new_key = (char*) calloc(strlen(key) + 1, sizeof(char));
    int aux;
    char chcompare;
    strcpy(new_key, key);
    for(int i = 0; i < columns - 1; i ++) {
        for(int j = i + 1; j < columns; j ++) {
            if(new_key[i] > new_key[j]) {
                aux = order[i];
                order[i] = order[j];
                order[j] = aux;
                chcompare = new_key[i];
                new_key[i] = new_key[j];
                new_key[j] = chcompare;
            }
        }
    }
    free(new_key);
}

void selectionSort2(int *order, int *reorder, int columns) {
    int aux1, aux2;
    for(int i = 0; i < columns - 1; i ++) {
        for(int j = i + 1; j < columns; j ++) {
            if(order[i] > order[j])
            {
                aux1 = reorder[i];
                reorder[i] = reorder[j];
                reorder[j] = aux1;
                aux2 = order[i];
                order[i] = order[j];
                order[j] = aux2;
            }
        }
    }
}

void codificationA(char *key, char *str) {
    double len = strlen(str);
    double lenCheie = strlen(key);

    int rows = (int)ceil(len / lenCheie);
    int columns = lenCheie;

//dynamically allocate the matrix according to the required dimensions
    char **matrix;
    matrix = (char **) calloc(rows, sizeof(char *));
    for (int i = 0; i < rows; i++)
        matrix[i] = (char *) calloc(columns, sizeof(char));

//I enter the string entered from the keyboard into the matrix on the lines
    int position = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            if (position >= len) {
                break;
            }
            matrix[i][j] = str[position++];
        }
    }

    int *order = (int *) calloc(columns, sizeof(int));

    for (int i = 0; i < columns; i++) {
        order[i] = i;
    }

// I sort the key according to alphabetical order, also changing the order of the vector
    selectionSort(key, order, columns);

//if the matrix element is not a letter, I add a space
    int codification_counter = 0;
    for (int j = 0; j < columns; j++) {
        for (int i = 0; i < rows; i++) {
            if (!isalpha(matrix[i][order[j]])) {
                str[codification_counter++] = ' ';
            }

// otherwise the str vector receives the column value given by the ordering of the key
            else {
                str[codification_counter++] = matrix[i][order[j]];
            }
        }
    }

    str[codification_counter] = 0;
    fputs(str, stdout);
    printf("\n");

    for (int i = 0; i < rows; i++) {
		free(matrix[i]);
	}
		free(order);
}

void decodificationA(char *key, char *str) {
    double len = strlen(str);
    double lenkey = strlen(key);

    int rows = (int)ceil(len / lenkey);
    int columns = lenkey;

//dynamically allocate the matrix according to the required dimensions
    char **matrix;
    matrix = (char **) calloc(rows, sizeof(char *));
    for (int i = 0; i < rows; i++)
        matrix[i] = (char *) calloc(columns, sizeof(char));

//I enter the string entered from the keyboard into the column matrix
    int position = 0;
    for (int j = 0; j < columns; j++) {
        for (int i = 0; i < rows; i++) {
            if (position >= len) {
                break;
            }
            matrix[i][j] = str[position++];
        }
    }

    int *order = (int *) calloc(columns, sizeof(int));
    int *reorder = (int *) calloc(columns, sizeof(int));
    for (int i = 0; i < columns; i++) {
        order[i] = i;
        reorder[i] = i;
    }

// I sort the key according to alphabetical order, also changing the order of the vector
    selectionSort(key, order, columns);


//I make another selection in which the order becomes an increasing ordered vector
//and reorder shows the position of each character depending on how the key is
//entered from the keyboard, memorizing the positions of how it was sorted
    selectionSort2(order, reorder, columns);

    int codification_counter = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {

//I enter the elements in the vector, while traversing the matrix line by line
            if (!isalpha(matrix[i][reorder[j]])) {
                str[codification_counter++] = ' ';
            } else {
                str[codification_counter++] = matrix[i][reorder[j]];
            }
        }
    }
    str[codification_counter] = 0;
    fputs(str, stdout);
    printf("\n");

    for (int i = 0; i < rows; i++)
        free(matrix[i]);
    free(order);
    free(reorder);
}

void codificationB(int key_B, char *str) {
    char *first = (char *) calloc(strlen(str) + 1, sizeof(char));

    if (key_B <= strlen(str)) {

//I use a "for" that goes through the last elements entered for the B key
        for (int i = strlen(str) - key_B; i < strlen(str); i++) {
            if (str[i] == ' ') {
                first[i - strlen(str) + key_B] = str[i];

//I compare with Z and z to check if the letter comes out of its area and make the necessary addition
            } else {
                int cryted_value = str[i] + key_B;
                if(cryted_value > 122){
                    int offset = cryted_value - 122;
                    first[i - strlen(str) + key_B] = offset + 64;
                }
                else if(cryted_value > 90 && str[i] <= 90 && str[i] >= 65){
                    int offset = cryted_value - 90;
                    first[i - strlen(str) + key_B] = offset + 96;
                }
                else {
                    first[i - strlen(str) + key_B] = cryted_value;
                }
            }
        }

//I add the rest of the remaining elements
        for (int i = 0; i < strlen(str) - key_B; i++) {
            first[key_B + i] = str[i];
        }
        int i = 0;
        while (first[i] != '\0') {
            printf("%c", first[i]);
            str[i] = first[i];
            i++;
        }

        printf("\n");
    }

    free(first);
}

void decodificationB(int key_B, char *str) {
    char *last = (char *) calloc(strlen(str) + 1, sizeof(char));

    if (key_B <= strlen(str)) {

//I use a force that goes through the first elements entered for key B
        for (int i = strlen(str) - key_B; i < strlen(str); i++) {
            if (str[i - strlen(str) + key_B] == ' ') {
                last[i] = str[i - strlen(str) + key_B];

//compare with "A" and "a" to check if the letter goes out of its area and make the necessary subtraction
            } else {
                int cryted_value = str[i - strlen(str) + key_B] - key_B;
                if(cryted_value < 65){
                    int offset = 65 - cryted_value;
                    last[i] = 121 - offset;
                }
                else if(cryted_value < 97 && str[i - strlen(str) + key_B] >= 97 && str[i - strlen(str) + key_B] <= 122){
                    int offset = 97 - cryted_value;
                    last[i] = 91 - offset;
                }
                else {
                    last[i] = cryted_value;
                }
            }
        }

//I add the rest of the elements at the beginning
        for (int i = 0; i < strlen(str) - key_B; i++) {
            last[i] = str[i + key_B];
        }
        int i = 0;
        while (last[i] != '\0') {
            printf("%c", last[i]);
            str[i] = last[i];
            i++;
        }

        printf("\n");
    }

    free(last);
}

int main() {
    char *line_read = (char *) calloc(100, sizeof(char));
    char *str = (char *) calloc(500, sizeof(char));

    fgets(str, 500, stdin);
    fgets(line_read, 100, stdin);
    line_read[strlen(line_read) - 1] = 0;
    str[strlen(str) - 1] = 0;

//I use a while that runs until "STOP" is entered from the keyboard
    while (strcmp(line_read, "STOP") != 0) {
        int space_index;
        for (space_index = 0; space_index < strlen(line_read); space_index++) {
            if (line_read[space_index] == ' ') {
                break;
            }
        }
//if the character before the space is A or B and the first character is C or D
//the necessary function will be used

        if (line_read[space_index - 1] == 'A') {
            if (line_read[0] == 'C') {
                codificationA(&line_read[space_index + 1], str);
            } else if (line_read[0] == 'D') {
                decodificationA(&line_read[space_index + 1], str);
            }

        } else if (line_read[space_index - 1] == 'B') {
            int codification_nr = atoi(&line_read[space_index + 1]);
            if (line_read[0] == 'C') {
                codificationB(codification_nr, str);
            } else if (line_read[0] == 'D') {
                decodificationB(codification_nr, str);
            }
        }

        fgets(line_read, 100, stdin);
        line_read[strlen(line_read) - 1] = 0;
    }

    free(line_read);
    free(str);

    return 0;
}
