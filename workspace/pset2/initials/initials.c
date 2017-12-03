// Implement a program that, given a person’s name, prints a person’s initials.
// https://docs.cs50.net/problems/initials/more/initials.html

#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void) {

    // get user's name via input
    string name = get_string();

    // iterate through each character
    for (int i = 0, n = strlen(name); i < n; i++) {

        char this_letter = name[i];
        char next_letter = name[i+1];
        char space = ' ';

        // if the first character isn't a space, output it
        if (i == 0 && this_letter != space) {
            printf("%c", toupper(this_letter));
        }

        // then output the next character after a space
        else if (this_letter == space && next_letter != space && next_letter >= 'A' && next_letter <= 'z') {
            printf("%c", toupper(next_letter));
        }
    }
    printf("\n");
}

