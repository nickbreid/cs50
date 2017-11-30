// this assignment asks for a height an outputs blocks in a pattern that 
// Mario jumps over in the first world, like so:

//  Height = 4
//    #  #
//   ##  ##
//  ###  ###
// ####  ####

#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int height;
    printf("Height: ");
    do
    {
        height = get_int();
    }
    while (height < 0 || height > 23);

    for (int i = 0; i < height; i++)
    {
        // print height - i - 1 spaces
        for (int j = 0; j < height - i; j++)
        {
            printf(" ");
        }
        // print i + 1 blocks
        for (int k = 0; k < i + 1; k++)
        {
            printf("#");
        }
        // print 2 spaces
        printf("  ");
        // print i + 1 blocks
        for (int k = 0; k < i + 1; k++)
        {
            printf("#");
        }
        // print a new line
        printf("\n");
    }

}
