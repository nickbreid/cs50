// Implement a program that encrypts messages using Caesar’s cipher

#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main(int argc, string argv[]) {

    if (argc != 2) {
        printf("Usage: ./caesar 13\n");
        return 1;
    }

    int k = atoi(argv[1]);
    k = k % 26;


    printf("key: %i\n", k);
    printf("plaintext: ");
    string plain_text = get_string();

    string cipher_text = plain_text;

    for (int i = 0, n = strlen(plain_text); i < n; i++) {
        char this_letter = plain_text[i];
        char mod_letter = plain_text[i];

        if (this_letter > 96 && this_letter < 123) {
            // lowercase

            if (this_letter + k > 122) {
                mod_letter = this_letter - (26 - k);
            } else {
                mod_letter = this_letter + k;
            }

        } else if (this_letter > 64 && this_letter < 91) {
            // uppercase

            if (this_letter + k > 90) {
                mod_letter = this_letter - (26 - k);
            } else {
                mod_letter = this_letter + k;
            }
        }

        cipher_text[i] = mod_letter;
    }


    printf("ciphertext: %s\n", cipher_text);
    return 0;

}