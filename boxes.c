#include<stdio.h>

void cleararray(int v[], int size) {
    for (int i = 0; i < size; i++)
        v[i] = 0;
}

//I check if the prisoners have taken an optimal number of steps

void validation(int P, int *box_number) {
    int prisoner_escaped = 1;
    int max_extractions = (int) P / 2;
    for (int i = 0; i < P; i++) {
        int number_of_extractions = 0;
        int number_in_box = box_number[i] - 1;

        for (int j = 0; j < P; j++) {
            number_of_extractions++;
            if (i == number_in_box) {
                break;
            }
            number_in_box = box_number[number_in_box] - 1;
        }
        if (number_of_extractions > max_extractions) {
            prisoner_escaped = 0;
            break;
        }
    }
    if (prisoner_escaped == 0)
        printf("Nu\n");
    else
        printf("Da\n");
}

//I check if the numbers in a cycle are repeated in the previous ones
int check_cycle_duplicates(int P, int *cycle_of_prisoner, int *cycles) {
    int OK = 1;
    for (int j = 1; j < P; j++) {
        if (cycle_of_prisoner[j] == 0 || OK == 0)
            break;
        for (int k = 0; k < P; k++) {
            if (cycle_of_prisoner[j] == cycles[k]) {
                OK = 0;
                break;
            }
        }
    }

    return OK;
}

//I calculate the cycle that each prisoner goes through
void find_cycle(int P, int *number_in_the_box, int *cicle_of_prisoner, int i, int prisoner_position) {
    cicle_of_prisoner[0] = i + 1;
    for (int j = 1; j < P; j++) {

//if the prisoner draws his number, break
        if (i == prisoner_position) {
            break;
        }

//if not, the next value of the cycle is given by the number in the box
//and the number of the box receives the next number drawn
        else if (i != prisoner_position) {
            cicle_of_prisoner[j] = prisoner_position + 1;
            prisoner_position = number_in_the_box[prisoner_position] - 1;
        }
    }
}

void choices(int P, int number_in_the_box[]) {
    int cycle_of_prisonier[500], cycles[2000];
    int size = 0;
    for (int i = 0; i < P; i++) {
        int prisoner_position = number_in_the_box[i] - 1;

        find_cycle(P, number_in_the_box, cycle_of_prisonier, i, prisoner_position);
        int OK = check_cycle_duplicates(P, cycle_of_prisonier, cycles);

//if the elements of a cycle are not found in the previous ones
//the cycles vector stores these values and prints the respective cycle
        if (OK == 1) {
            for (int j = 0; j < P; j++) {
                cycles[size] = cycle_of_prisonier[j];
                size++;
                if (cycle_of_prisonier[j + 1] == 0) {
                    printf("%d\n", cycle_of_prisonier[j]);
                    break;
                } else
                    printf("%d ", cycle_of_prisonier[j]);
            }
        }

//delete the elements from the respective prisoner cycle
//to move on to a new cycle
        cleararray(cycle_of_prisonier, 500);
    }
}

int main() {
    int i, size, cycle[500];
    cleararray(cycle, 500);

    scanf("%d", &size);
    for (i = 0; i < size; i++) {
        scanf("%d", &cycle[i]);
    }

    validation(size, cycle);
    choices(size, cycle);

    return 0;
}
