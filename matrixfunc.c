#include <stdio.h>
#include "matrixfunc.h"

void sumRows(const int *matptr, int rows, int cols)
{
    int i;
    int j;
    int sum;

    for (i = 0; i < rows; i++)
    {
        sum = 0;

        for (j = 0; j < cols; j++)
        {
            sum += *(matptr + i * cols + j);
        }

        printf("Сумма элементов строки %d: %d\n", i + 1, sum);
    }
}

int countGreater(const int *matptr, int rows, int cols, int k)
{
    int i;
    int j;
    int count = 0;

    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            if (*(matptr + i * cols + j) > k)
            {
                count++;
            }
        }
    }

    return count;
}

int lastNegative(const int *matptr, int rows, int cols, int *value)
{
    int i;
    int j;
    int found = 0;

    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            if (*(matptr + i * cols + j) < 0)
            {
                *value = *(matptr + i * cols + j);
                found = 1;
            }
        }
    }

    return found;
}
