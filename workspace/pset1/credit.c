#include <stdio.h>
#include <cs50.h>

int main(void) {

    long long int n;
    long long int p;
    long long int temp;
    int total = 0;
    int o = 0;

    // get credit card number as input and validate that it's the proper format
    do {
    printf("Input a 13- to 16-digit credit card number to check if it's valid:\n> ");
    n = get_long_long();

    } while (n < 1000000000000 || n > 9999999999999999);

    p = n;
    temp = n;

    // starting at the second-to-last digit, add to the total each digit times 2
    // If that product is 10 or more, break those digits apart and add each one
    while(n) {
        n /= 10;

        if (n % 10 * 2 > 9) {
            o = n % 10 * 2;
            total += 1 + o % 10;
            // printf("add 2 to the total\nadd %i to the total\n", o % 10);
        } else {
            // printf("add %lld to the total\n", n % 10 * 2);
            total += n % 10 * 2;
        }

        n /= 10;
    }

    // using the original number, start again at the last digit and add each
    // unmultiplied digit to the total.

    while(p) {
        total += p % 10;
        // printf("add %lld to the total\n", p % 10);
        p /= 100;
    }

    // if the total % 10 == 0, then it may be a valid credit card number
    // so check if it starts with a company's sequence

    if (total % 10 == 0) {

        while (temp > 100) {
            temp = temp / 10;
        }

        int company_id = temp;

        if (company_id == 34 || company_id == 37) {
            printf("AMEX\n");
        } else if (company_id > 50 && company_id < 56) {
            printf("MASTERCARD\n");
        } else if (company_id / 10 == 4) {
            printf("VISA\n");
        } else {
            printf("This is a mathmatically valid credit card number that isn't associated with a known company.\n");
        }
    } else {
        printf("INVALID\n");
    }
}
