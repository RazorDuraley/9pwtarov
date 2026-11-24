#include <stdio.h>
#include "matrixfunc.h"

#define MAX_SIZE 100

int readInt(int *value)
{
    int result;
    int ch;

    result = scanf("%d", value);

    if (result == EOF)
    {
        return -1;
    }

    if (result != 1)
    {
        while ((ch = getchar()) != '\n' && ch != EOF)
        {
        }

        return 0;
    }

    while ((ch = getchar()) != '\n' && ch != EOF)
    {
    }

    return 1;
}

void printMatrix(const int *matptr, int rows, int cols)
{
    int i;
    int j;

    printf("\nМатрица и адреса ее элементов:\n");

    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            printf("%6d (%p)  ",
                   *(matptr + i * cols + j),
                   (void *)(matptr + i * cols + j));
        }

        printf("\n");
    }
}

int main(void)
{
    int matrix[MAX_SIZE][MAX_SIZE];
    int rows = 0;
    int cols = 0;
    int hasSize = 0;
    int isFilled = 0;
    int i;
    int j;
    int value;
    int k;
    int result;
    int lastValue;
    char choice;
    int ch;

    while (1)
    {
        printf("\n");
        printf("a  Задать размер матрицы\n");
        printf("b  Заполнить матрицу\n");
        printf("c  Представление матрицы (значения и адреса)\n");
        printf("d  Сумма элементов каждой строки\n");
        printf("e  Количество элементов больше заданного k\n");
        printf("f  Последний отрицательный элемент матрицы\n");
        printf("g  Выход\n");
        printf("Выберите пункт: ");

        result = scanf(" %c", &choice);

        if (result == EOF)
        {
            printf("\nКонец ввода. Завершение программы.\n");
            break;
        }

        while ((ch = getchar()) != '\n' && ch != EOF)
        {
        }

        if (choice == 'g')
        {
            printf("Программа завершена.\n");
            break;
        }
        else if (choice == 'a')
        {
            printf("Введите количество строк (от 1 до %d): ", MAX_SIZE);
            result = readInt(&rows);

            if (result == -1)
            {
                printf("\nКонец ввода. Завершение программы.\n");
                break;
            }

            if (result == 0 || rows < 1 || rows > MAX_SIZE)
            {
                printf("Некорректное количество строк.\n");
                continue;
            }

            printf("Введите количество столбцов (от 1 до %d): ", MAX_SIZE);
            result = readInt(&cols);

            if (result == -1)
            {
                printf("\nКонец ввода. Завершение программы.\n");
                break;
            }

            if (result == 0 || cols < 1 || cols > MAX_SIZE)
            {
                printf("Некорректное количество столбцов.\n");
                continue;
            }

            hasSize = 1;
            isFilled = 0;
            printf("Размер матрицы установлен: %d x %d.\n", rows, cols);
        }
        else if (choice == 'b')
        {
            if (!hasSize)
            {
                printf("Сначала задайте размер матрицы.\n");
                continue;
            }

            printf("Введите элементы матрицы:\n");

            for (i = 0; i < rows; i++)
            {
                for (j = 0; j < cols; j++)
                {
                    while (1)
                    {
                        printf("Элемент [%d][%d]: ", i + 1, j + 1);
                        result = readInt(&value);

                        if (result == -1)
                        {
                            printf("\nКонец ввода. Завершение программы.\n");
                            return 0;
                        }

                        if (result == 1)
                        {
                            matrix[i][j] = value;
                            break;
                        }

                        printf("Ошибка: введите целое число.\n");
                    }
                }
            }

            isFilled = 1;
            printf("Матрица заполнена.\n");
        }
        else if (choice == 'c')
        {
            if (!isFilled)
            {
                printf("Сначала задайте размер и заполните матрицу.\n");
                continue;
            }

            printMatrix(&matrix[0][0], rows, cols);
        }
        else if (choice == 'd')
        {
            if (!isFilled)
            {
                printf("Сначала задайте размер и заполните матрицу.\n");
                continue;
            }

            sumRows(&matrix[0][0], rows, cols);
        }
        else if (choice == 'e')
        {
            if (!isFilled)
            {
                printf("Сначала задайте размер и заполните матрицу.\n");
                continue;
            }

            printf("Введите значение k: ");
            result = readInt(&k);

            if (result == -1)
            {
                printf("\nКонец ввода. Завершение программы.\n");
                break;
            }

            if (result == 0)
            {
                printf("Некорректный ввод k.\n");
                continue;
            }

            printf("Количество элементов больше %d: %d\n",
                   k, countGreater(&matrix[0][0], rows, cols, k));
        }
        else if (choice == 'f')
        {
            if (!isFilled)
            {
                printf("Сначала задайте размер и заполните матрицу.\n");
                continue;
            }

            if (lastNegative(&matrix[0][0], rows, cols, &lastValue))
            {
                printf("Последний отрицательный элемент: %d\n", lastValue);
            }
            else
            {
                printf("В матрице нет отрицательных элементов.\n");
            }
        }
        else
        {
            printf("Неизвестный пункт меню. Выберите a, b, c, d, e, f или g.\n");
        }
    }

    return 0;
}
