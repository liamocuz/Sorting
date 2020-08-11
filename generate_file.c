#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>

// Command Line: give it an int for number of values in the file and the file name
// ./generate_file[0] n[1] divisor[2] file[3] (len 4)

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