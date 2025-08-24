#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "Rus");
    int X, Y, n, j, i, result;
    printf("Введите целые и неотрицательные числа X и Y, а программа выдаст вам результат возведения числа X в степень Y \n");
    printf("Введите значение X: ");
    
    while (scanf("%d", &X) != 1 || X < 0 ) {
        printf("Ошибка: Введите целое и неотрицательное число X\n");
        while (getchar() != '\n'); // очистка буфера ввода
    }
    printf("Введите значение Y: ");
    while (scanf("%d", &Y) != 1 || Y < 0) {
        printf("Ошибка: Введите целое и неотрицательное число Y\n");
        while (getchar() != '\n'); // очистка буфера ввода
    }


    result = X;
    
   	if (X == 0){
       result = 0;
   	} else if (X == 1){
       result = 1;
   	} else if (Y == 0){
       result = 1;
   	} else if (Y == 1){
       result = X;
   	} else{
        for(i = 1; i < Y; i++){
                n = result;
                for (j = 1; j < X; j ++){
                result += n;
            }
        }
   }
   
    printf("%d в степени %d равно %d\n", X, Y, result);
    return 0;
}