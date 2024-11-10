#include <stdio.h>

void predigit(char num1, char num2);
void postdigit(char c, int n);

char romanval[100];  // Adjusted size to 100 for typical Roman numerals (sufficient for numbers < 4000)
int i = 0;

int main() {
    int j;
    long number;

    // Take input number from user
    printf("Enter the number: ");
    scanf("%ld", &number);
    
    if (number <= 0) {
        printf("Invalid number\n");
        return 0;
    }

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
    for (j = 0; j < i; j++)
        printf("%c", romanval[j]);
    printf("\n");

    return 0;
}

void predigit(char num1, char num2) {
    romanval[i++] = num1;
    romanval[i++] = num2;
}

void postdigit(char c, int n) {
    int j;
    for (j = 0; j < n; j++)
        romanval[i++] = c;
}
