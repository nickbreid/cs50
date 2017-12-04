// Implement a program that cracks passwords
// https://docs.cs50.net/problems/crack/crack.html

#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <crypt.h>


int main(int argc, string argv[]) {

    // the program should be run with one command-line argument, a hash
    if (argc != 2) {
        printf("Usage: ./crack hash\n");
        return 1;
    }

    // initialize the input hash, a given salt, and the valid characters
    string input_hash = argv[1];
    char * salt = "50";
    char alphabet[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int try_counter = 0;


    // first test if the password is one letter (return is a match is found)
    for(int i = 0, n = strlen(alphabet); i < n ; i++) {

        char test_plain[2];
        test_plain[0] = alphabet[i];
        test_plain[1] = '\0';
        string test_pw = crypt(test_plain, salt);

        if (strcmp(test_pw, input_hash) == 0) {
            printf("PASSWORD IS: %s\n\n", test_plain);
            return 0;
        }
        try_counter++;
    }

    // test if the password is two letters
    for(int i = 0, n = strlen(alphabet); i < n ; i++) {
        for(int j = 0; j < n; j++) {

            char test_plain[3];
            test_plain[0] = alphabet[i];
            test_plain[1] = alphabet[j];
            test_plain[2] = '\0';
            string test_pw = crypt(test_plain, salt);

            if (strcmp(test_pw, input_hash) == 0) {
                printf("PASSWORD IS: %s\n\n", test_plain);
                return 0;
            }
            try_counter++;
            if (try_counter % 100 == 0) {
                printf("Tried %i passwords so far...\n", try_counter);
            }
        }
    }

    // test if the password is three letters
    for(int i = 0, n = strlen(alphabet); i < n ; i++) {
        for(int j = 0; j < n; j++) {
            for(int k = 0; k < n; k++) {

                char test_plain[4];
                test_plain[0] = alphabet[i];
                test_plain[1] = alphabet[j];
                test_plain[2] = alphabet[k];
                test_plain[3] = '\0';
                string test_pw = crypt(test_plain, salt);

                if (strcmp(test_pw, input_hash) == 0) {
                    printf("PASSWORD IS: %s\n\n", test_plain);
                    return 0;
                }
                try_counter++;
                if (try_counter % 1000 == 0) {
                    printf("Tried %i passwords so far...\n", try_counter);
                }
            }
        }
    }

    // test if the password is four letters
    for(int i = 0, n = strlen(alphabet); i < n ; i++) {
        for(int j = 0; j < n; j++) {
            for(int k = 0; k < n; k++) {
                for(int l = 0; l < n; l++) {
                    char test_plain[5];
                    test_plain[0] = alphabet[i];
                    test_plain[1] = alphabet[j];
                    test_plain[2] = alphabet[k];
                    test_plain[3] = alphabet[l];
                    test_plain[4] = '\0';
                    string test_pw = crypt(test_plain, salt);

                    if (strcmp(test_pw, input_hash) == 0) {
                        printf("PASSWORD IS: %s\n\n", test_plain);
                        return 0;
                    }
                    try_counter++;
                    if (try_counter % 1000 == 0) {
                        printf("Tried %i passwords so far...\n", try_counter);
                    }
                }
            }
        }
    }

    return 0;
}