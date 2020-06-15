#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "sorting.h"

//helper function declarations
//Quick sort functions declartaion
void Q_sort(long *array, int low, int high);
int find_partition(long *array, int low, int high);
void swap(long *a, long *b); //, int j);

//merge sort function declaration

//QUICKSORT=================================================================

// This function finds a random pivot point and swaps it with the highest element
void randomize_pivot(long *array, int low, int high);
void randomize_pivot(long *array, int low, int high)
{
    srand(time(NULL));
    int pivot = low + rand() % (high - low);
    int temp = array[high];
    array[high] = array[pivot];
    array[pivot] = temp;
    //swap(array, num, high);
}

//This fucntion does partition and sub array operations
int find_partition(long *array, int first, int last)
{
    int i, j, pivot;
    long temp;

    pivot = first;
    i = first;
    j = last;

    while (i < j)
    {
        while (array[i] <= array[pivot] && i < last)
            i++;
        while (array[j] > array[pivot])
            j--;
        if (i < j)
        {
            temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        }
    }

    temp = array[pivot];
    array[pivot] = array[j];
    array[j] = temp;

    return j;
}

//recursive function to do quicksort on array
void Q_sort(long *array, int first, int last)
{

    if (first < last)
    {

        int pivot = find_partition(array, first, last);
        Q_sort(array, first, pivot - 1);
        Q_sort(array, pivot + 1, last);
    }
}

void Quick_Sort(long *Array, int Size)
{
    int low = 0;
    int high = Size - 1;
    //printf("SIZE = %d\n", Size);

    Q_sort(Array, low, high);
}

//MERGE SORT FUNCTIONS
void merge(long *array, int first, int mid, int last);
void M_sort(long *array, int first, int last);

void merge(long *array, int first, int mid, int last)
{
    //printf("\nsize of temp = %d\n", last - first + 1);
    long *temp = malloc(sizeof(long) * (last - first + 1));
    if (temp == NULL)
    {
        printf("malloc fail!\n");
        return;
    }
    //&temp[] = {0};
    int num1 = mid - first + 1;
    int num2 = last - mid;
    // long *destination = &(temp[0]);
    // long *source = &(array[first]);
    // memcpy(destination, source, sizeof(long) * num1);

    // destination = &temp[mid + 1];
    // source = &array[mid + 1];
    // memcpy(destination, source, (sizeof(long) * num2));

    for (int i = 0; i < (mid - first + 1); i++)
    {
        temp[i] = array[first + i];
    }

    for (int j = 0; j < (last - mid); j++)
    {
        temp[mid - first + 1 + j] = array[mid + 1 + j];
    }
    // printf("first = %d\nmid = %d\nlast = %d\n", first, mid, last);
    // for (int z = 0; z < (last - first + 1); z++)
    // {
    //     printf("%ld\n", temp[z]);
    // }

    // //tracking variables
    int i = 0;
    int j = mid + 1;

    for (int k = first; k <= last; k++)
    {

        if (temp[i] < temp[j])
        {
            array[k] = temp[i];
            i++;
        }
        else if (temp[i] >= temp[j])
        {
            array[k] = temp[j];
            j++;
        }
        else if (i < num1)
        {
            array[k] = temp[i];
            i++;
        }
        else if (j < num2) //if (j < num2)
        {
            array[k] = temp[j];
            j++;
        }
        // if (i < num1)
        // {
        //     array[k] = temp[i];
        //     i++;
        // }
        // else if (j < num2)
        // {
        //     array[k] = temp[j];
        //     j++;
        // }
        // else if (temp[i] < temp[j])
        // {
        //     array[k] = temp[i];
        //     i++;
        // }
        // else
        // {
        //     array[k] = temp[j];
        //     j++;
        // }
    }
    free(temp);
}
void M_sort(long *array, int first, int last)
{
    if (first >= last)
    {
        return;
    }

    int mid = (first + last) / 2;
    M_sort(array, first, mid);
    M_sort(array, mid + 1, last);
    // long *temp = malloc(sizeof(long) * (last - first + 1));
    // if (temp == NULL)
    // {
    //     printf("malloc fail!\n");
    //     return;
    // }

    // for (int i = 0; i<)
    merge(array, first, mid, last);
}

void Merge_Sort(long *Array, int Size)
{
    int last = Size - 1;
    M_sort(Array, 0, last); //first is 0, last is size - 1 for 1st iteration
    //printf("MERGE SORT in fucnction!\n");
}