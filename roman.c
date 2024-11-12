#include <stdio.h>
#include <stdlib.h>  // For system() function

// Function prototypes
void predigit(char num1, char num2);
void postdigit(char c, int n);
void clearScreen();  // Function to clear the screen

// Global variables
char romanval[100];  // Array to store Roman numeral result
int i = 0;

// ANSI color codes
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"

void printWelcomeMessage() {
    printf(CYAN "==============================================\n");
    printf("          WELCOME TO THE GAME                 \n");
    printf("        GAME NAME: ROMAN NUMBER CONVERTER     \n");
    printf("      ======================================  \n");
    printf("            Developed by:                     \n");
    printf("          - Developer 1: Mann Shah            \n");
    printf("          - Developer 2: Taniksha Shah        \n");
    printf("          - Developer 3: Tisha Shah           \n");
    printf("      =====================================   \n");
    printf("   Press any key to start the game...         \n");
    printf("==============================================\n" RESET);
}

int main() {
    int j;
    long number;
    char continueGame;

    printWelcomeMessage();
    getchar();  // Wait for user input to proceed
    clearScreen();  // Clear the screen after the introduction

    // Loop to keep running the game until the user decides to exit
    do {
        i = 0;  // Reset the Roman numeral index
        printf(GREEN "Enter a positive number to convert to Roman numeral (Press 0 to exit): " RESET);

        // Input validation
        while (scanf("%ld", &number) != 1) {
            printf(RED "Invalid input. Please enter a positive number: " RESET);
            while (getchar() != '\n'); // Clear invalid input
        }

        // Check if the user wants to exit
        if (number == 0) {
            break;  // Exit the loop if the user enters 0
        }

        // Convert the number to Roman numeral
        while (number != 0) {
            if (number >= 1000) {
                postdigit('M', number / 1000);
                number -= (number / 1000) * 1000;
            }
            else if (number >= 900) {
                predigit('C', 'M');
                number -= 900;
            }
            else if (number >= 500) {
                postdigit('D', number / 500);
                number -= (number / 500) * 500;
            }
            else if (number >= 400) {
                predigit('C', 'D');
                number -= 400;
            }
            else if (number >= 100) {
                postdigit('C', number / 100);
                number -= (number / 100) * 100;
            }
            else if (number >= 90) {
                predigit('X', 'C');
                number -= 90;
            }
            else if (number >= 50) {
                postdigit('L', number / 50);
                number -= (number / 50) * 50;
            }
            else if (number >= 40) {
                predigit('X', 'L');
                number -= 40;
            }
            else if (number >= 10) {
                postdigit('X', number / 10);
                number -= (number / 10) * 10;
            }
            else if (number >= 9) {
                predigit('I', 'X');
                number -= 9;
            }
            else if (number >= 5) {
                postdigit('V', number / 5);
                number -= (number / 5) * 5;
            }
            else if (number >= 4) {
                predigit('I', 'V');
                number -= 4;
            }
            else if (number >= 1) {
                postdigit('I', number);
                number = 0;
            }
        }

        // Print the resulting Roman numeral
        printf(YELLOW "Roman numeral is: " RESET);
        for (j = 0; j < i; j++) {
            printf("%c", romanval[j]);
        }
        printf("\n");

    } while (1);  // Infinite loop until the user decides to exit

    printf(CYAN "Thank you for playing! Goodbye!\n" RESET);
    return 0;
}

// Function to handle the addition of a Roman numeral character
void postdigit(char c, int n) {
    for (int j = 0; j < n; j++) {
        romanval[i++] = c;
    }
}

// Function to handle the addition of a Roman numeral character with a preceding character
void predigit(char num1, char num2) {
    romanval[i++] = num1;
    romanval[i++] = num2;
}

// Function to clear the screen
void clearScreen() {
    system("cls || clear");
}

