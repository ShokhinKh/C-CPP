 /*
 
 ������������ ������ �6
 
 ������� 26
 
 ������ ������ �������, �������������� �������� ��� ��������� � ���������� ��������� � ������ (�� 2 �� 15). 
 ��������� ������ ������ ��������� ������� ��� ����� ���������, ������� �������� ���������� ����� �������� 
 ��������� ������. �������� ������ ������ ���� ��������� ������.
 
*/



#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>


//���������� �������� �������� � value. ������������� ����������� �� ���� (a <=
// * value <= b)*/
void input(int a, int b, int *value);

//���� ��������� ������������� ������� ������� n � ������ ������� ����� group.
//���������� ����� ������ ������� 
int input_array(int n, int group, double *arr);

//���������� ��� ����� � � b. ������������ �������� �������
double search_nod(double a, double b);

//������������ ��� ��� ������ ������ ������� group � ������������ ������� arr
// * ������� n. ��������� ������������ � ������ ������� ����� ������
void computation(int n, int group, double *arr);

//������� ������������ ������ arr ������� n � �������
void out_array(double *arr, int n);

int main() {
    
  double array[32] = {0};
  int n = 0, group = 0, arr_end = 0;

  setlocale(LC_ALL, "Rus");

  printf("������� ���-�� ��������� (�� ������ 20): ");
  input(0, 20, &n);
  printf("������� ���-�� ��������� � ������ (�� 2 �� 15): ");
  input(2, 15, &group);

  arr_end = input_array(n, group, array);

  printf("�������� ������:\n");
  out_array(array, arr_end);

  computation(n, group, array);

  printf("�������� ������:\n");
  out_array(array, arr_end);

  return 0;
}

void input(int a, int b, int *value) {
    while (scanf("%d", &*value) != 1 || *value < a || *value > b) {
        printf("������������ ����, �������� �����\n");
        while (getchar() != '\n');
    }
}
    

int input_array(int n, int group, double *arr) {
  int new = n + (n / group);
  int i, j, cnt = 0;

  for (i = 0; i < new; i += group + 1) {
    for (j = 0; j < group && cnt != n; j++, cnt++) {
      printf("������� %d �������� \n", cnt + 1);
      if (!scanf("%lf", &arr[i + j])) {
        char ch;
        printf("���������� ����, �������� �����\n");
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
