#include <stdio.h>

void printmin(int arr[], int len)
{
    int i;
    int min = arr[0];
    for (i = 1; i < len; i++)
    {
        if (arr[i] < min)
        {
            min = arr[i];
        }
    }
    printf("MIN: %d\n", min);
}

void printmax(int arr[], int len)
{
    int max = arr[0];
    for (int i = 1; i < len; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    printf("MAX: %d\n", max);

}

void printmittelwert(int arr[], int len)
{
    int sum = 0;
    for (int i = 0; i < len; i++)
    {
        sum += arr[i];
    }
    int mw = sum / len;
    printf("SUM: %d, MW: %d\n", sum, mw);
}

void removeElement(int *numbers, int length, int position)
{
    for (int i = 0; i < length; i++)
    {
        if (i == position)
        {
            for (i = position; i < length; i++)
            {
                numbers[i] = numbers[i+1];
            }
        }
    }
    for (int i = 0; i < length-1; i++)
    {
        printf("%d", numbers[i]);
    }
}

int main()
{
    int arr[4] = {2,3,4,5};
    int len = sizeof(arr) / sizeof(arr[0]);
    printmin(arr, len);
    printmax(arr, len);
    printmittelwert(arr, len);
    int pos = 1;
    removeElement(arr, len, pos);
}