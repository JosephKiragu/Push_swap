#include <stdio.h>

void quickSort(int array[], int left, int right)
{
    int     i;
    int     j;
    int     pivot;
    int     temp;

    if (left < right)
    {
        pivot = left;
        i = left;
        j = right;
        while (i < j)
        {
            while(array[i] <= array[pivot] && i <= right)
            {
                i++;
            }
            while(array[j] > array[pivot] && j >= left)
            {
                j--;
            }
            if (i <j)
            {
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
        temp = array[j];
        array[j] = array[pivot];
        array[pivot] = temp;

        quickSort(array, left, j - 1);
        quickSort(array, j + 1, right);
    }
}

int *getRanges(int array[])
{
    static int range[4];
    int i;
    int j;

    i = 0;
    j = 0;
    // while(j < 4)
    // {
    //     range[j] = array[i];
    //     i += 4;
        
    //     if (j > 1 && i - j == 4)
    //         i++;
    //     j++;
    // }
    // range[0] = array[0];
    // range[1] = array[4];
    // range[2] = array[5];
    // range[3] = array[9];

    j = 0;

    while (j < 4)
    {
        printf("ranges = %d",range[j]);
        j++;
    }
    printf("\n");
    return range;
}

int main()
{
    int array[] = {9, 8, 7,6,5,4,3,2,1,0};
    int n = sizeof(array) / sizeof(int);
    int j;
    int i;
    int k;
    int m;
    int arr[2][2];
    int range[] = {0,4,5,9};

    quickSort(array, 0, n-1);
    j = 0;
    while(j < n)
    {
        printf("%d", array[j]);
        j++;
    }
    

 
    i = 0;
    k = 0;
    m = 0;
    while (i<2)
    {
        k = 0;
        while( k < 2)
        {
            arr[i][k] = range[m];
            k++;
            m++;
        }
        i++;
    }
    printf("\n");

    i = 0;
    k = 0;
    while (i<2)
    {
        k = 0;
        while( k < 2)
        {
            printf("%d",arr[i][k]);
            k++;
            m++;
        }
        i++;
    }
    printf("\n");

    int *ranges = getRanges(array);


    
}