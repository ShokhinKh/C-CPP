/*    
Добавить вывод индексов, добавить вывод длины и ширины, индексирование с 1 для пользователя,
сделать так, чтобы qsort работал при отдельном выборе, а не после кажддого вывода функций.
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 25

typedef struct {
    double length;
    double width;
} Rectangle;

int compare(const void *a, const void *b);

char orientation(double length, double width);

void input_f(double *a, const char *msg);

void inputRec(Rectangle *rectangle);

void addRectangle(Rectangle rectangles[], int *size);

void insertRecIn(Rectangle rectangles[], int *size, int index);

void removeRecIn(Rectangle rectangles[], int *size, int index);

void removeAll(Rectangle rectangles[], int *size);

void printRec(Rectangle rectangle);

void printAll(Rectangle rectangles[], int size);

void printRecIn(Rectangle rectangles[], int size, int index);

void Menu();

void MenuChoice(Rectangle rectangles[], int *size);

void sortAll(Rectangle rectangles[], int *size);

int main() {
    system("chcp 65001 > nul"); // Установка кодировки UTF-8
    Rectangle rectangles[MAX_SIZE];
    int size = 0;
    MenuChoice(rectangles, &size);
    return 0;
}

// Функция для отображения меню
void Menu() {
    printf("\nМеню:\n");
    printf("1. Добавить прямоугольник\n");
    printf("2. Вставить прямоугольник по индексу\n");
    printf("3. Удалить прямоугольник по индексу\n");
    printf("4. Удалить все прямоугольники\n");
    printf("5. Просмотреть все прямоугольники\n");
    printf("6. Посмотреть прямоугольник по индексу\n");
    printf("7. Сортировка\n");
    printf("8. Завершить программу\n");
    printf("Выберите ваш вариант: ");
}

//функция для обработки выбора в меню
void MenuChoice(Rectangle rectangles[], int *size) {
    int choice, index;

    while (1) {
        Menu();     

        while (scanf("%d", &choice) != 1 || choice < 1 || choice > 8) {
            printf("Ошибка ввода, попробуйте еще раз: ");
            while (getchar() != '\n');
        }

        switch (choice) {
            case 1: // добавление
                addRectangle(rectangles, size);
                break;
            case 2: // вставка оп индексу
                printf("Введите индекс для вставки: ");
                while (scanf("%d", &index) != 1 || index < 0 || index > *size) {
                    printf("Ошибка ввода, попробуйте еще раз: ");
                    while (getchar() != '\n');
                }
                insertRecIn(rectangles, size, index);
                break;
            case 3: // удаление по индексу
                printf("Введите индекс для удаления: ");
                while (scanf("%d", &index) != 1 || index < 0 || index >= *size) {
                    printf("Ошибка ввода, попробуйте еще раз: ");
                    while (getchar() != '\n');
                }
                removeRecIn(rectangles, size, index);
                break;
            case 4: // удаление всего 
                removeAll(rectangles, size);
                break;
            case 5: // вывод всего
                printAll(rectangles, *size);
                break;
            case 6: //просмотр по индексу
                printf("Введите индекс для просмотра: ");
                while (scanf("%d", &index) != 1 || index < 0 || index >= *size) {
                    printf("Ошибка ввода, попробуйте еще раз: ");
                    while (getchar() != '\n');
                }
                printRecIn(rectangles, *size, index);
                break;
            case 7:
                sortAll(rectangles, size);
                printf("Отсортированный массив:\n");
                printAll(rectangles, *size);
                break;
            case 8:
                printf("Программа завершена.\n");
                return;
        }
    }
}

// Сравнение для qsort
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

// Определение ориентации
char orientation(double length, double width) {
    if (length > width) {
        return 'H';
    } else if (length < width) {
        return 'V';
    } else {
        return 'Q';
    }
}

// Проверка на ввод длины и ширины
void input_f(double *a, const char *msg) {
    if (msg) {
        printf("%s\n", msg);
    }

    while (scanf("%lf", a) != 1 || *a <= 0) {
        printf("Ошибка ввода, попробуйте еще раз\n");
        while (getchar() != '\n');
    }
}

// Ввод данных прямоугольника
void inputRec(Rectangle *rectangle) {
    input_f(&rectangle->length, "Введите длину прямоугольника:");
    input_f(&rectangle->width, "Введите ширину прямоугольника:");
}

// Добавление прямоугольника
void addRectangle(Rectangle rectangles[], int *size) {
    if (*size >= MAX_SIZE) {
        printf("Массив заполнен, невозможно добавить новый элемент!\n");
        return;
    }
    printf("Добавление нового прямоугольника:\n");
    inputRec(&rectangles[(*size)++]);
    // qsort(rectangles, *size, sizeof(Rectangle), compare);
}

// Вставка прямоугольника по индексу
void insertRecIn(Rectangle rectangles[], int *size, int index) {
    if (*size >= MAX_SIZE) {
        printf("Массив заполнен, невозможно вставить элемент!\n");
        return;
    }
    for (int i = *size; i > index; --i) {
        rectangles[i] = rectangles[i - 1];
    }
    printf("Вставка нового прямоугольника на индекс %d:\n", index);
    inputRec(&rectangles[index]);
    ++*size;
    // qsort(rectangles, *size, sizeof(Rectangle), compare);
}

void sortAll(Rectangle rectangles[], int *size) {
    qsort(rectangles, *size, sizeof(Rectangle), compare);
}

// Удаление прямоугольника по индексу
void removeRecIn(Rectangle rectangles[], int *size, int index) {
    for (int i = index; i < *size - 1; ++i) {
        rectangles[i] = rectangles[i + 1];
    }
    --*size;
    printf("Прямоугольник на индексе %d удален.\n", index);
}

// Удаление всех прямоугольников
void removeAll(Rectangle rectangles[], int *size) {
    *size = 0;
    printf("Все прямоугольники удалены.\n");
}

// Вывод данных одного прямоугольника
void printRec(Rectangle rectangle) {
    printf("Длина: %.0f;\nШирина: %.0f;\nПлощадь: %.0f;\nОриентация: %c.\n", rectangle.length, rectangle.width, rectangle.length * rectangle.width, orientation(rectangle.length, rectangle.width));
}

// Вывод всех прямоугольников
void printAll(Rectangle rectangles[], int size) {
    if (size == 0) {
        printf("Массив пуст.\n");
        return;
    }
    printf("\nВсе прямоугольники:\n");
    printf("%0s %15s %15s %15s %20s\n", "id", "Длина", "Ширина", "Площадь", "Ориентация");
    printf("----------------------------------------------------------\n");

    for (int i = 0; i < size; ++i) {
        printf("%d %9.0f %9.0f %9.0f %9.0c\n", i, rectangles[i].length, rectangles[i].width, rectangles[i].length * rectangles[i].width, orientation(rectangles[i].length, rectangles[i].width));
    }
}

// Вывод данных одного прямоугольника по индексу
void printRecIn(Rectangle rectangles[], int size, int index) {
    if (index >= 0 && index < size) {
        printf("Прямоугольник на индексе %d:\n", index);
        printRec(rectangles[index]);
    } else {
        printf("Неверный индекс.\n");
    }
}
