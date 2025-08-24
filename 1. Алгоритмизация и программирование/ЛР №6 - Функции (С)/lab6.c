 /*
 
 Лабораторная работа №6
 
 Вариант 26
 
 Заданы размер массива, действительные значения его элементов и количество элементов в группе (от 2 до 15). 
 Дополнить каждую группу исходного массива еще одним элементом, который содержит наибольший общий делитель 
 элементов группы. Неполная группа должна быть дополнена нулями.
 
*/



#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>


//Записывает введённое значение в value. Устанавливает ограничение на ввод (a <=
// * value <= b)*/
void input(int a, int b, int *value);

//Ввод элементов вещественного массива размера n с учётом размера групп group.
//Возвращает новый размер массива 
int input_array(int n, int group, double *arr);

//Возвращает НОД чисел а и b. Используется алгоритм Евклида
double search_nod(double a, double b);

//Рассчитывает НОД для каждой группы размера group в вещественном массиве arr
// * размера n. Результат записывается в каждый элемент после группы
void computation(int n, int group, double *arr);

//Выводит вещественный массив arr размера n в консоль
void out_array(double *arr, int n);

int main() {
    
  double array[32] = {0};
  int n = 0, group = 0, arr_end = 0;

  setlocale(LC_ALL, "Rus");

  printf("Введите кол-во элементов (Не больше 20): ");
  input(0, 20, &n);
  printf("Введите кол-во элементов в группе (От 2 до 15): ");
  input(2, 15, &group);

  arr_end = input_array(n, group, array);

  printf("Исходный массив:\n");
  out_array(array, arr_end);

  computation(n, group, array);

  printf("Конечный массив:\n");
  out_array(array, arr_end);

  return 0;
}

void input(int a, int b, int *value) {
    while (scanf("%d", &*value) != 1 || *value < a || *value > b) {
        printf("Некорректный ввод, попробуй снова\n");
        while (getchar() != '\n');
    }
}
    

int input_array(int n, int group, double *arr) {
  int new = n + (n / group);
  int i, j, cnt = 0;

  for (i = 0; i < new; i += group + 1) {
    for (j = 0; j < group && cnt != n; j++, cnt++) {
      printf("Введите %d значение \n", cnt + 1);
      if (!scanf("%lf", &arr[i + j])) {
        char ch;
        printf("Некорекный ввод, попробуй снова\n");
        while (((ch = getchar()) != '\n') && (ch != EOF))
          ;
        j--, cnt--;
      }
    }
  }

  return i;
}

double search_nod(double a, double b) {
  while (a != 0 && b != 0) {
    if (a > b) {
      a = fmod(a, b);
    } else {
      b = fmod(b, a);
    }
  }
  return a + b;
}

void computation(int n, int group, double *arr) {
  int new = n + (n / group);
  int i, j, cnt = 0;

  for (i = 0; i < new; i += group + 1) {
    double result = arr[i];
    for (j = 1; j < group && cnt != n; j++, cnt++) {
      result = search_nod(result, arr[i + j]);
    }

    arr[i + group] = result;
  }
}

void out_array(double *arr, int n) {
  int i;
  for (i = 0; i < n; i++) {
    printf("%.2lf ", arr[i]);
  }
  putchar('\n');
}
