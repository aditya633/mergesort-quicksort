
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sorting.h"

void printArray(long *vecArr, int size)
{
    int ind = 0;
    for (ind = 0; ind < size; ind++)
    {
        printf("%ld", vecArr[ind]);
        printf("\n");
    }
}

long *Array_Load_From_File(char *filename, int *size)
{

    FILE *fp;
    int count = 0; //number of long integers

    fp = fopen(filename, "rb");
    if (fp == NULL)
    {
        size = 0;
        return NULL;
    }

    long num; // temporary variable
    while (!feof(fp))
    {
        fread(&num, sizeof(long), 1, fp);
        count++;
    }
    count--;
    //printf("exit loop\n");
    *size = count; //asign number of elements to count

    long *ptr = malloc(sizeof(long) * count);
    if (ptr == NULL)
    {
        size = 0;
        return NULL;
    }

    fseek(fp, 0, SEEK_SET);
    fread(ptr, sizeof(long), count, fp);

    fclose(fp);
    return ptr;
}

int Array_Save_To_File(char *filename, long *array, int size)
{
    FILE *fp;
    fp = fopen(filename, "wb");
    int temp = 0;
    if (fp == NULL)
    {
        size = 0;
        return 0;
    }

    fseek(fp, 0, SEEK_SET);
    temp = fwrite(array, sizeof(long), size, fp);

    fclose(fp);
    return temp;
}
int cmpfunc(const void *a, const void *b)
{
    if (*(long *)a < *(long *)b)
        return -1;
    if (*(long *)a > *(long *)b)
        return 1;
    return 0;
}
void Sort_test(long *array, long *array_copy, int size);
void Sort_test(long *array, long *array_copy, int size)
{

    for (int i = 0; i < size; i++)
    {
        array_copy[i] = array[i];
    }
    printf("ORIGINAL:\n");
    printArray(array_copy, size);
    qsort(array_copy, size, sizeof(long), cmpfunc);

    //FILE * fp = fopen("correct_sorted.b", "wb");

    Array_Save_To_File("correct_sorted.b", array_copy, size);
    //printf("\nsorted for testing purposes, size = %d\n", size);
    printf("\nCORRECT SORT:\n");

    printArray(array_copy, size);
}

int main(int argc, char **argv)
{

    int size = 0;
    long *array = NULL;

    if (argc != 4)
    {
        return EXIT_FAILURE;
    }
    array = Array_Load_From_File(argv[2], &size);
    if (array == NULL)
    {
        return EXIT_FAILURE;
    }
    long *array_copy = malloc(sizeof(long) * size);
    Sort_test(array, array_copy, size);
    free(array_copy);
    if (strcmp((const char *)argv[1], "-q") == 0)
    {

        printf("QUICKSORT! ORIGINAL ARRAY\n");
        //printArray(array, size);

        Quick_Sort(array, size);

        // printf("\nimpletemnted sorted!\n");
        //  printArray(array, size);

        Array_Save_To_File(argv[3], array, size);
        free(array);
        return EXIT_SUCCESS;
    }
    else if (strcmp(argv[1], "-m") == 0)
    {

        printf("MERGE SORT!\n");
        //printArray(array, size);
        Merge_Sort(array, size);
        printf("\nSORTED BY MERGE OSRT\n");
        printArray(array, size);
        Array_Save_To_File(argv[3], array, size);
        free(array);
        return EXIT_SUCCESS;
    }
    else
    {
        printf("please enter a valid input!");
        return EXIT_SUCCESS;
    }
}
