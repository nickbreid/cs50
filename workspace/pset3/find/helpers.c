/**
 * helpers.c
 *
 * Helper functions for Problem Set 3.
 */

#include <cs50.h>

#include "helpers.h"

void sort(int values[], int n);

int maximum(int * array, int size){

  int current = 0;
  int max = 0;

  for(current = 0; current < size; current++){
    if(array[current] > max){ max = array[current]; }
  }

  return max;
}

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    if (n < 1) {
       return 1;
    }

    sort(values, n);
    int first_index = 0;
    int last_index = n - 1;
    int halfway = (first_index + last_index) / 2;

    while (first_index <= last_index)
    {
        halfway = (first_index + last_index) / 2;
        if (values[halfway] == value) {
            return true;
        }
        if (values[halfway] > value) {
            last_index = halfway - 1;
        }
        if (values[halfway] < value) {
            first_index = halfway + 1;
        }
    }

    printf("Value not found.");
    return 0;
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    int low = 0;
    int high = 65536;
    int sorted = 0;

    int * counting_array;
    counting_array = calloc(high - low + 1, sizeof(int));

    for (int i = low; i < high; i++) {
        counting_array[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        int value = values[i];
        counting_array[value]++;
    }

    for (int i = low; i < high; i++) {
        if (counting_array[i] != 0) {
            for (int j = 0; j < counting_array[i]; j++) {
                values[sorted + j] = i;
                sorted++;
            }
        }
    }
    return;
}



