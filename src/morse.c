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
    int menu_choice = getchar();
    int dummy = getchar();

    if (menu_choice == '1' && dummy == 10) {
        letters_to_morse();
    } else if (menu_choice == '2' && dummy == 10) {
        morse_to_letters();
    } else {
        achtung();
    }
}

void remove_last_symbol(char* string, char symbol) {
    char* last_symbol = string + strlen(string) - 1;
    if (strlen(string) > 0 && *last_symbol == symbol) {
        *last_symbol = 0;
    }
}

void letters_to_morse() {
    char codes[36][7] = {".-",    "-...",  "-.-.",  "-..",   ".",     "..-.",  "--.",   "....",  "..",
                         ".---",  "-.-",   ".-..",  "--",    "-.",    "---",   ".--.",  "--.-",  ".-.",
                         "...",   "-",     "..-",   "...-",  ".--",   "-..-",  "-.--",  "--..",  "-----",
                         ".----", "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----."};
    char* result_string = calloc(1, sizeof(char));
    char symbol;
    while ((symbol = (char)getchar()) && symbol != '\n' && symbol != EOF) {
        if (symbol == ' ') {
            remove_last_symbol(result_string, ' ');
            append_string(&result_string, "", '\t');
        } else if (toupper(symbol) >= 'A' && toupper(symbol) <= 'Z') {
            append_string(&result_string, codes[toupper(symbol) - 'A'], ' ');
        } else if (symbol >= '0' && symbol <= '9') {
            append_string(&result_string, codes[symbol - '0' + 26], ' ');
        } else {
            free(result_string);
            achtung();
        }
    }
    remove_last_symbol(result_string, ' ');
    printf("%s", result_string);
    free(result_string);
}

int morse_to_code(const char* morse_symbol) {
    char binary_string[] = {'1', 0, 0, 0, 0, 0, 0};
    for (int i = 0; morse_symbol[i]; i++) {
        binary_string[i + 1] = morse_symbol[i] == '.' ? '0' : '1';
    }
    return strtol(binary_string, NULL, 2);
}

void morse_to_letters() {
    char codes[] = {0,   0,   'E', 'T', 'I', 'A', 'N', 'M', 'S', 'U', 'R', 'W', 'D', 'K', 'G', 'O',
                    'H', 'V', 'F', 0,   'L', 0,   'P', 'J', 'B', 'X', 'C', 'Y', 'Z', 'Q', 0,   0,
                    '5', '4', 0,   '3', 0,   0,   0,   '2', 0,   0,   0,   0,   0,   0,   0,   '1',
                    '6', 0,   0,   0,   0,   0,   0,   0,   '7', 0,   0,   0,   '8', 0,   '9', '0'};
    char morse_symbol[6] = {0};
    char symbol;
    while ((symbol = (char)getchar()) && symbol != '\n' && symbol != EOF) {
        if (symbol == '.' || symbol == '-') {
            char tmp_string[2] = {symbol, 0};
            strcat(morse_symbol, tmp_string);
        } else if (symbol == ' ' || symbol == '\t') {
            printf("%c", codes[morse_to_code(morse_symbol)]);
            printf(symbol == '\t' ? " " : "");
            memset(morse_symbol, 0, 6);
        } else {
            achtung();
        }
    }
    printf("%c", codes[morse_to_code(morse_symbol)]);
}