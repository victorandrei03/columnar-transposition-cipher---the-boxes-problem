**THE BOXES PROBLEM**
1.1. Statement <br />
In a prison, there are P prisoners. The prison is about to close, so the prison director proposes a game to the prisoners.
In a room, P boxes numbered from 1 to P will be placed in a random order. Each box contains a different number from 1 to P, which may differ from the number on the box. The prisoners will enter the room one by one and must find the box that contains their own number inside it. Each prisoner is allowed to open only P/2 boxes. If all the prisoners find their respective numbers, they will be released. If even one prisoner fails to find their number, everyone loses.
Since randomly choosing the P/2 boxes for each prisoner is not cost-effective for a large number of prisoners, one of them came up with a solution that gives everyone a higher chance of success.
Their strategy is as follows: each prisoner first opens the box corresponding to their own number. For example, prisoner Y opens box Y. Inside this box is a number Z. They continue to open box Z, which in turn contains another number T, and they will open that one as well, repeating the steps until they find their number or until they have opened the maximum number of boxes, P/2. This significantly increases the likelihood of finding the box that contains their number. Each prisoner will create a list of all the boxes they have opened until they reach the end (either by finding their number in order or by opening P/2 boxes). The prisoners will enter the room in order, starting with number 1, followed by 2, up to P.
Your role is that of the director, and you need to pay attention to the progress of the game in order to display the following at the end:
"Yes" if the prisoners win the game or "No" if they lose the game.
All the cycles formed by the boxes, each on a new line. The boxes form a cycle if starting from one box, they end up at the same box. These lists of boxes will be displayed in ascending order: first, the cycle starting from box 1, followed by the cycle starting from the next box (which is not part of the previous cycles), and so on. Note that we are referring to the box number, not its content.
1.2. Input
• The first line will contain the number P of prisoners.
• P integers, separated by a space. The first number represents the content of box 1, the second number represents the content of box 2, and so on.
1.3. Output
• For the first requirement, only "Yes" or "No" should be printed on the first line.
• For requirement number 2, print all the cycles.
1.4. Constraints and Clarifications
• 2 ≤ P ≤ 500;
• An implementation done entirely in the main() function will not be scored! Implement auxiliary functions.
• Global variables are not allowed.
1.5. Examples
1.5.1. Example 1
Example 1
Input Output Explanation
6
3 6 2 1 4 5
No
1 3 2 6 5 4
Prisoner 1 opens the box at position 1, which contains the number 3, so the next box opened by Prisoner 1 will be the one at position 3, which contains the number 2. They will also open the box at the second position, which contains the number 6. Since the prisoner has exhausted the number of boxes they are allowed to open and hasn't found their number, the prisoners will lose the game.
Also, the cycle is not complete (it didn't return to the starting box), and following the same rule, it is discovered that all the boxes belong to the same cycle.
1.5.2. Example 2
Example 2
Input Output Explanation
10
4 5 2 7 1 8 3 6 10 9
No
1 4 7 3 2 5
6 8
9 10
They are allowed to open a maximum of 5 boxes.
Prisoner 1: 1 → 4 → 7 → 3 → 2 (they didn't find their number, so they will lose the game).
The cycles are:
1 → 4 → 7 → 3 → 2 → 5, starting from 5 it reaches box 1.
6 → 8, starting from 8 it reaches 6.
9 → 10, starting from 10 it reaches 9.
1.5.3. Example 3
Example 3
Input Output Explanation
10
4 5 1 7 8 9 3 2 10 6
Yes
1 4 7 3
2 5 8
6 9 10
They are allowed to open a maximum of 5 boxes.
Prisoner 1: 1 → 4 → 7 → 3 → 1 (box 3 contains the order number of prisoner 1).
Prisoner 2: 2 → 5 → 8 → 2 (box 8 contains the order number of prisoner 2).
...
Prisoner 10: 10 → 6 → 9 → 10.
Thus, all the prisoners find their numbers.
The cycles are:
1 → 4 → 7 → 3, starting from 3 it reaches box 1.
2 → 5 → 8, starting from 8 it reaches 2.
6 → 9 → 10, starting from 10 it reaches 6.

INTERFERED TRANSMISSION
3.1. Statement
Ana and Bob are in different cities. They constantly change their positions and never reach the same city at the same time, so they want to communicate through messages. There is an antenna that transmits messages from one city to another. The problem is that all antennas in this network encrypt the transmitted message. If Ana sends a message, Bob will receive an altered version of it depending on the distance between the two cities. Each antenna has a different encoding method. There are only 2 encoding methods, and they allow the original message to be decoded because the entire message can be reproduced through the inverse operation. The operations are as follows:
❖ Encoding A - Columnar Transposition Cipher
This encoding requires a key in addition to the input text. We use a matrix with the same number of columns as the length of the key and as many rows as necessary to cover the entire input text. The text will be written line by line in the matrix. The columns will be read successively in the order of the ASCII values of the characters in the key.
❖ Encoding B
The text will be shifted to the right by a given number of characters.
"Ana are mere", 5 -> " mereAna are"
Additionally, the shifted characters will be modified by adding the number of characters to their ASCII code.
" mereAna are" -> " rjwjAna are"
The increase/decrease in the ASCII code will only be done within the ASCII range of alphabet characters. If it reaches the character 'z' and there are 2 more characters to be increased, the result will be 'B' (from 'z' to 'A' and from 'A' to 'B'). If it reaches the character 'Z' and there are 2 more characters to be increased, the result will be 'b'. If it needs to be decreased by 2 characters from 'A', the result will be 'y' (from 'A' to 'z' and from 'z' to 'y'). If it needs to be decreased by 2 characters from 'a', the result will be 'Y'.
During the rotation, spaces remain spaces! See examples 3, 4, 5.
❖ Decoding A
Involves reversing the steps of Encoding A.
❖ Decoding B
Involves reversing the steps of Encoding B.
3.2. Input
• The initial text will be read on the first line.
• On the following lines, the names of the operations to be applied (EncodingA, EncodingB, DecodingA, DecodingB) will be read, followed by a space and the encoding argument (char* for A and int for B).
• Reading will stop when "STOP" is entered.
3.3. Output
The program will display the result of each operation (encoding/decoding) after each operation.
3.4. Constraints and Clarifications
• The text to be encrypted has a maximum length of 100 characters.
• The key used for encryption A has a maximum length of 20 characters.
• The key used for encryption B has a maximum value equal to the length of the text.
• Each encoding and decoding operation should be implemented in a separate function.
• An implementation done entirely in the main() function will not be scored! Implement auxiliary functions! Do not use global variables!
• The encodings and decodings will be called from the main function according to the execution mode.
3.5. Testing and Scoring
• The maximum score is 40 points.
• The source code containing the main function must be named: codifications.c
3.6. Examples
For a better understanding, the output will be underlined (to highlight where spaces will be). You don't have to underline in your output!
3.6.1. Example 1
Example 1
In:
"Eu pup poala popii popa pupa poala mea"
EncodingB 7
STOP
Out:
hsh tlhEu pup poala ppii popa pupa po
Example 2:
In:
Ana are mere mari
EncodingA merele
STOP
Out:
n m erre ariAe ama
![image](https://github.com/victorandrei03/columnar-transposition-cipher---the-boxes-problem/assets/117905946/22065b19-1c1e-43c3-a91a-ef9888cff30b)

Example 3:
In:
Eu pup poala popii popa pupa poala mea
EncodingA cadelnita
STOP
Out:
ulp aoipm Ea ae aop p po ppa upaa po l piu

Example 4:
In:
Ana are mere
EncodingB 5
STOP
Out:
rjwjAna are

Example 5:
In:
Un vultur sta pe pisc cu un pix in plisc
EncodingB 5
STOP
Out:
uqnxhUn vultur sta pe pisc cu un pix in

Example 6:
In:
Ana are mere
EncodingA Bob
EncodingB 6
DecodingB 6
DecodingA Bob
STOP
Out:
“A ee arme na r “
“ tg x A ee arme”
“A ee arme na r “
“Ana are mere   “
