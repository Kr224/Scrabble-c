#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main() {
    int n, w, x, y;   // Declaring variables for the size, no. of words and coordinates of the words
    char d;
    bool valid = true;
    int matches = 0;

    scanf("%d", &n); // Storing size of 2-d array in variable n

    char board[n][n]; // Declaring a 2-d array of size nxn
    char word[n];   // Declaring an array of size n to take the word as input

    scanf("%d", &w); // Storing no. of words in variable w

    for (int i = 0; i < n; i++) {         // Initializing the array to '.'
        for (int j = 0; j < n; j++) {
            board[i][j] = '.';
        }
    }

    for (int i = 0; i < w; i++) {    // Outer for-loop so it runs exactly w times
        scanf("%d %d %c %s", &x, &y, &d, word);  // Taking user input for w lines

        size_t wordLength = strlen(word);  // To find the exact length of the word array

        if ((d == 'H' && x + wordLength > n) || (d == 'V' && y + wordLength > n)) {      // if word extends board, it does not stay valid
            printf("Invalid word placement:  (%d,%d) %c, %s\n", x, y, d, word);
            valid = false;
            continue;
        }

        if (d == 'H') {
            for (int i = 0; i < wordLength; i++) {
                if (board[y][x + i] != '.') {
                    if (word[i] == board[y][x + i]) {
                        matches++;
                    } else {
                        valid = false;
                        break;
                    }
                }
            }
        } else if (d == 'V') {
            for (int i = 0; i < wordLength; i++) {
                if (board[y + i][x] != '.') {
                    if (word[i] == board[y + i][x]) {
                        matches++;
                    } else {
                        valid = false;
                        break;
                    }
                }
            }
        }

        if (matches == 0 && i > 0) {
            valid = false;
            printf("Invalid word placement:  (%d,%d) %c, %s\n", x, y, d, word);

        } else {
            valid = true;
        }


        if (d == 'H' && valid) {            /*This code block is for all the legal words that should be printed on the final board*/
            for (int i = 0; i < wordLength; i++) {
                board[y][x] = word[i];
                x++;
            }
        } else if (d == 'V' && valid ) {
            for (int i = 0; i < wordLength; i++) {
                board[y][x] = word[i];
                y++;
            }
        }
    }

    for (int i = 0; i < n; i++) {           //Printing out the final board
        for (int j = 0; j < n; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }


    int f;
    int b, a;
    char l;
    scanf("%d", &f);

    for (int m = 0; m < f; m++) {
        scanf("%d %c %d", &b, &l, &a);
    }

    for (int row = 0; row < n; row++) {
        for (int col = 0; col < n; col++) {
            if (board[row][col] == l) {
                if (col - b >= 0 && col + a < n) {     // Check if the word can be placed horizontally
                    bool canPlaceHorizontally = true;
                    for (int k = col - b; k <= col + a; k++) {
                        if (board[row][k] != '.' && board[row][k] != l) {
                            canPlaceHorizontally = false;
                            break;
                        }
                    }
                    if (canPlaceHorizontally) {
                        printf("Place horizontally at (%d,%d)\n", col, row);
                    }
                }

                if (row - b >= 0 && row + a < n) {  // Check if the word can be placed vertically
                    bool canPlaceVertically = true;
                    for (int k = row - b; k <= row + a; k++) {
                        if (board[k][col] != '.' && board[k][col] != l) {
                            canPlaceVertically = false;
                            break;
                        }
                    }
                    if (canPlaceVertically) {
                        printf("Place vertically at (%d,%d)\n", col, row);
                    }
                }
            }
        }
    }

return 0;
}






