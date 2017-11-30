#include <stdio.h>
#include <cs50.h>

int main(void)
{
    printf("How long did you spend in the shower? (in minutes)\n> ");
    int minutes = get_int();
    printf("You consumed the equivalent of %i bottles of water.\n", minutes * 12);
}