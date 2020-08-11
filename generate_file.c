#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>

/*
This program generates a file of random integers that can be used to sort.

How to use:
./executable[0] n[1] divisor[2] file[3]

n - the amount of numbers to sort
divisor - the value used to modulo the random value (ex. rand() % 100 will keep all values 0 - 99)
file - the path to the file location
*/

int main (int argc, char** argv)
{
    if (argc != 4)
    {
        printf("Incorrect amount of arguments.\n");
        return EXIT_FAILURE;
    }

    FILE *fptr = fopen(argv[3], "w");
    if (fptr == NULL)
    {
        printf("Error with file pointer.\n");
        return EXIT_FAILURE;
    }

    time_t t;

    srand((unsigned) time(&t));

    long int n = strtol(argv[1], NULL, 10);
    long int div = strtol(argv[2], NULL, 10);

    for (int i = 0; i < n; i++)
    {
        fprintf(fptr, "%d\n", rand() % (int)div);
    }

    fclose(fptr);

    return EXIT_SUCCESS;

}