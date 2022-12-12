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

int main()
{
    int array[] = {9, 8, 7,6,5,4,3,2,1,0};
    int n = sizeof(array) / sizeof(int);
    int ranges[2][2];

    quickSort(array, 0, n-1);

    
}