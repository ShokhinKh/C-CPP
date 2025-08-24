/*
Лабораторная работа №7 

Варинат 7

Задано множество прямоугольников(не более 25), для каждого из которых указаны 
длины сторон. Обеаспечить сортировку по площади и оперделить ориентацию (горизонтальная или вертикальная)
каждого прямоугольника.   

*/


#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 25

typedef struct {
    double length; 
    double width; 
} Rectangle;

// ввод прямоугольников
int inputNum();

// для qsort
int compare(const void *a, const void *b);

// определения ориентации
char orientation(double length, double width);

// для ввода данных
void inputRec(Rectangle *rectangle);

// вывод данных
void printRec(Rectangle rectangle);

void printAll();

int main() {
    system("chcp 65001 > nul");

    printAll();

    return 0;
}


int inputNum() {
    int n;
    printf("Введите количество прямоугольников (макс %d): ", MAX_SIZE);
    while (scanf("%d", &n) != 1 || n <= 0 || n > MAX_SIZE) {
        printf("Неправильный ввод, попробуйте еще раз\n");
        while (getchar() != '\n');
    }
    return n;
}


int compare(const void *a, const void *b) {
    Rectangle *ra = (Rectangle *)a;
    Rectangle *rb = (Rectangle *)b;
    if (ra->length * ra->width > rb->length * rb->width) {
        return 1;
    } else if (ra->length * ra->width < rb->length * rb->width) {
        return -1;
    } else {
        return 0;
    }
}


char orientation(double length, double width) {
    if (length > width) {
        return 'H'; // Горизонтальный
    } else if (length < width) {
        return 'V'; // Вертикальный
    }else {
        return 'Q'; // Квадрат
    }
}


void input_f(double *a, const char *msg) {

    if (msg) {
        printf("%s\n", msg);
    }

    while (scanf("%lf", a) != 1 || *a <= 0) {
        printf("Ошибка ввода, попробуйте еще раз\n");
        while (getchar() != '\n');
    }
}


void inputRec(Rectangle *rectangle) {
    input_f(&rectangle->length, "Введите длину прямоугольника:");
    input_f(&rectangle->width, "Введите ширину прямоугольника:");
}


void printRec(Rectangle rectangle) {
  printf("%.0f \t %c\n", rectangle.length * rectangle.width, orientation(rectangle.length, rectangle.width));
}

void printAll() {
    Rectangle rectangles[MAX_SIZE];
    
    int n = inputNum();

    int i;
    for (i = 0; i < n; ++i) {
        printf("\nВвод данных для прямоугольника №%d:\n", i + 1);
        inputRec(&rectangles[i]);
    }


    qsort(rectangles, n, sizeof(Rectangle), compare);

    printf("\n%1s %20s\n", "Площадь", "Ориентация");
    printf("----------------------------------------\n");

    for (i = 0; i < n; ++i) {
        printRec(rectangles[i]);
    }
}
