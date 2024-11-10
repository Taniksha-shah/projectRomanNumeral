#include <stdio.h>
#include <stdlib.h>  // For system() function

// Function prototypes
void predigit(char num1, char num2);
void postdigit(char c, int n);
void clearScreen();  // Function to clear the screen

// Global variables
char romanval[100];  // Array to store Roman numeral result
int i = 0;

int main() {
    int j;
    long number;
    char continueGame;

    // Display game introduction
    printf("==============================================\n");
    printf("          WELCOME TO THE GAME                 \n");
    printf("        GAME NAME: ROMAN NUMBER CONVERTER     \n");
    printf("      ======================================  \n");
    printf("            Developed by:                     \n");
    printf("          - Developer 1: Mann Shah            \n");
    printf("          - Developer 2: Taniksha Shah        \n");
    printf("          - Developer 3: Tisha Shah           \n");
    printf("      =====================================   \n");
    printf("   Press any key to start the game...         \n");
    printf("==============================================\n");

    getchar();  // Wait for user input to proceed

    clearScreen();  // Clear the screen after the introduction

    // Loop to keep running the game until the user decides to exit
    do {
        i = 0;  // Reset the Roman numeral index
        printf("Enter the number: ");
        scanf("%ld", &number);

        if (number <= 0) {
            printf("Invalid number. Please enter a number greater than 0.\n");
        } else {
            // Convert the number to Roman numeral
            while (number != 0) {
                if (number >= 1000) {
                    postdigit('M', number / 1000);
                    number = number - (number / 1000) * 1000;
                }
                else if (number >= 900) {
                    predigit('C', 'M');
                    number = number - 900;
                }
                else if (number >= 500) {
                    postdigit('D', number / 500);
                    number = number - (number / 500) * 500;
                }
                else if (number >= 400) {
                    predigit('C', 'D');
                    number = number - 400;
                }
                else if (number >= 100) {
                    postdigit('C', number / 100);
                    number = number - (number / 100) * 100;
                }
                else if (number >= 90) {
                    predigit('X', 'C');
                    number = number - 90;
                }
                else if (number >= 50) {
                    postdigit('L', number / 50);
                    number = number - (number / 50) * 50;
                }
                else if (number >= 40) {
                    predigit('X', 'L');
                    number = number - 40;
                }
                else if (number >= 10) {
                    postdigit('X', number / 10);
                    number = number - (number / 10) * 10;
                }
                else if (number >= 9) {
                    predigit('I', 'X');
                    number = number - 9;
                }
                else if (number >= 5) {
                    postdigit('V', number / 5);
                    number = number - (number / 5) * 5;
                }
                else if (number >= 4) {
                    predigit('I', 'V');
                    number = number - 4;
                }
                else if (number >= 1) {
                    postdigit('I', number);
                    number = 0;
                }
            }

            // Print the resulting Roman numeral
            printf("Roman numeral is: ");
            for (j = 0; j < i; j++) {
                printf("%c", romanval[j]);
            }
            printf("\n");
        }

        // Ask if the user wants to continue
        printf("Do you want to convert another number? (y/n): ");
        scanf(" %c", &continueGame);  // Space before %c to consume any leftover newline character

        if (continueGame == 'y' || continueGame == 'Y') {
            clearScreen();  // Clear the screen for the next conversion
        }

    } while (continueGame == 'y' || continueGame == 'Y');  // Continue if the user presses 'y' or 'Y'

    // Exit message
    printf("Thank you for using the Roman Numeral Converter!\n");
    return 0;
}

// Function to handle two characters for values like 900, 400, etc.
void predigit(char num1, char num2) {
    romanval[i++] = num1;
    romanval[i++] = num2;
}

// Function to handle multiple characters like 'X' for 10, 'I' for 1, etc.
void postdigit(char c, int n) {
    int j;
    for (j = 0; j < n; j++) {
        romanval[i++] = c;
    }
}

// Function to clear the screen (for Windows)
void clearScreen() {
    system("cls");
}

