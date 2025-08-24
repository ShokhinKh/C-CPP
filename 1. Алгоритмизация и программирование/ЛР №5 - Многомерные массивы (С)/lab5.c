/*
Лабораторная работа №5 

Вариант 25 

Задание: 
Задано количество строк и столбцов матрицы. Заполнить матрицу целыми числами по спирали, 
начиная с левого верхнего угла по часовой стрелке. 

*/


#include <stdio.h>
#include <stdlib.h>
#include <locale.h>


#define MAX_COLS 15

int main() {

    setlocale(LC_ALL, "Rus");

    int rows, cols;

    // Запрос у пользователя количества строк и столбцов

    printf("Введите количество строк (max %d): ", MAX_ROWS);
    while (scanf("%d", &rows) != 1 || rows <= 0 || rows > MAX_COLS) {
        printf("Ошибка: Введите целое и неотрицательное число не больше 15\n");
        while (getchar() != '\n'); // очистка буфера ввода
    }


    printf("Введите количество столбцов (max %d): ", MAX_COLS);
    while (scanf("%d", &cols) != 1 || cols <= 0 || cols > MAX_COLS) {
        printf("Ошибка: Введите целое и неотрицательное число не больше 15\n");
        while (getchar() != '\n'); // очистка буфера ввода
    }

    // Создание и заполнение матрицы
    int matrix[MAX_ROWS][MAX_COLS];
    int num = 1;
    int startRow = 0;
    int startCol = 0;
    int endRow = rows - 1;
    int endCol = cols - 1;

    while (startRow <= endRow && startCol <= endCol) {
        // Заполнение верхней строки матрицы
        
        int i;
        for (i = startCol; i <= endCol; i++) {
            matrix[startRow][i] = num++;
        }
        startRow++;

        // Заполнение правого столбца матрицы
        int j;
        for (j = startRow; j <= endRow; j++) {
            matrix[j][endCol] = num++;
        }
        endCol--;

        // Заполнение нижней строки матрицы
        if (startRow <= endRow) {
            int k;
            for (k = endCol; k >= startCol; k--) {
                matrix[endRow][k] = num++;
            }
            endRow--;
        }

        // Заполнение левого столбца матрицы
        if (startCol <= endCol) {
            int m;
            for (m = endRow; m >= startRow; m--) {
                matrix[m][startCol] = num++;
            }
            startCol++;
        }
    }

    // Вывод матрицы на экран
    printf("Итоговая таблица:\n");
    int l;
    for (l = 0; l < rows; l++) {
        int n;
        for (n = 0; n < cols; n++) {
            printf("%d\t", matrix[l][n]);
        }
        printf("\n");
    }

    return 0;
}
