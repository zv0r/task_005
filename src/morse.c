#include "morse.h"

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "misc.h"

int main(void) {
    menu();
    exit(EXIT_SUCCESS);
}

void menu() {
    int menu_choice = 0;
    scanf("%d", &menu_choice);
    fflush(stdin);
    getchar();
    switch (menu_choice) {
        case 1:
            letters_to_morse();
            break;
        case 2:
            morse_to_letters();
            break;
        default:
            achtung();
            break;
    }
}

void letters_to_morse() {
    char codes[36][7] = {".-",    "-...",  "-.-.",  "-..",   ".",     "..-.",  "--.",   "....",  "..",
                         ".---",  "-.-",   ".-..",  "--",    "-.",    "---",   ".--.",  "--.-",  ".-.",
                         "...",   "-",     "..-",   "...-",  ".--",   "-..-",  "-.--",  "--..",  "-----",
                         ".----", "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----."};
    char* result_string = calloc(1, sizeof(char));
    char symbol;
    while ((symbol = getchar()) && symbol != '\n' && symbol != EOF) {
        if (symbol == ' ') {
            append_string(&result_string, "", '\t');
        } else if (toupper(symbol) >= 'A' && toupper(symbol) <= 'Z') {
            append_string(&result_string, codes[toupper(symbol) - 'A'], ' ');
        } else if (symbol >= '0' && symbol <= '9') {
            append_string(&result_string, codes[symbol - '0' + 26], ' ');
        } else if ((symbol == '\n' || symbol == EOF) && strlen(result_string) > 0) {
            // result_string[strlen(result_string) - 1] = 0;
        } else {
            free(result_string);
            achtung();
        }
    }
    if (strlen(result_string) > 0) {
        result_string[strlen(result_string) - 1] = 0;
    }
    printf("%s", result_string);
    free(result_string);
}

void morse_to_letters() {}