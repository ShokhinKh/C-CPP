#include <stdio.h>
#include <stdlib.h>

typedef struct {
    double length;
    double width;
} Rectangle;

int compare(const void *a, const void *b);

char orientation(double length, double width);

void input_f(double *a, const char *msg);

void inputRec(Rectangle *rectangle);

void addRectangle(Rectangle **rectangles, int *size);

void insertRecIn(Rectangle **rectangles, int *size, int index);

void removeRecIn(Rectangle **rectangles, int *size, int index);

void removeAll(Rectangle **rectangles, int *size);

void printRec(Rectangle rectangle);

void printAll(Rectangle *rectangles, int size);

void printRecIn(Rectangle *rectangles, int size, int index);

void Menu();

void MenuChoice(Rectangle **rectangles, int *size);

void saveInFile(Rectangle *rectangles, int size);

void readFromFile(Rectangle **rectangles, int *size);

void sortAll(Rectangle *rectangles, int size);

Rectangle* resizeArray(Rectangle *rectangles, int newSize) {
    Rectangle *newRectangles = realloc(rectangles, newSize * sizeof(Rectangle));
    if (!newRectangles) {
        printf("Ошибка выделения памяти!\n");
        exit(1);  // Завершение программы при ошибке
    }
    return newRectangles;
}

int main() {
    system("chcp 65001 > nul");
    Rectangle *rectangles = NULL;
    int size = 0;
    MenuChoice(&rectangles, &size);
    removeAll(&rectangles, &size); // Освободить память при выходе
    return 0;
}

// Функция для отображения меню
void Menu() {
    printf("\nМеню:\n");
    printf(" 1. Добавить прямоугольник\n");
    printf(" 2. Вставить прямоугольник по индексу\n");
    printf(" 3. Удалить прямоугольник по индексу\n");
    printf(" 4. Удалить все прямоугольники\n");
    printf(" 5. Просмотреть все прямоугольники\n");
    printf(" 6. Посмотреть прямоугольник по индексу\n");
    printf(" 7. Сортировка\n");
    printf(" 8. Сохранить данные в файл\n");
    printf(" 9. Загрузить данные из файла\n");
    printf("10. Завершить программу\n");
    printf("Выберите ваш вариант: ");
}

// Функция для обработки выбора в меню
void MenuChoice(Rectangle **rectangles, int *size) {
    int choice, index;

    while (1) {
        Menu();

        while (scanf("%d", &choice) != 1 || choice < 1 || choice > 10) {
            printf("Ошибка ввода, попробуйте еще раз: ");
            while (getchar() != '\n');
        }

        switch (choice) {
            case 1: // добавление
                addRectangle(rectangles, size);
                break;
            case 2: // вставка по индексу
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
                printAll(*rectangles, *size);
                break;
            case 6: // просмотр по индексу
                printf("Введите индекс для просмотра: ");
                while (scanf("%d", &index) != 1 || index < 0 || index >= *size) {
                    printf("Ошибка ввода, попробуйте еще раз: ");
                    while (getchar() != '\n');
                }
                printRecIn(*rectangles, *size, index);
                break;
            case 7: // сортировка
                sortAll(*rectangles, *size);
                printf("Отсортированный массив:\n");
                printAll(*rectangles, *size);
                break;
            case 8: // сохранить в файл
                saveInFile(*rectangles, *size);
                break;
            case 9: // загрузить из файла
                readFromFile(rectangles, size);
                printAll(*rectangles, *size);
                break;
            case 10: // завершение
                removeAll(rectangles, size);
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
void addRectangle(Rectangle **rectangles, int *size) {
    *rectangles = resizeArray(*rectangles, *size + 1); // Увеличение массива для нового прямоугольника
    printf("Добавление нового прямоугольника:\n");
    inputRec(&(*rectangles)[*size]); // Ввод данных для нового прямоугольника
    (*size)++;
}

// Вставка прямоугольника по индексу
void insertRecIn(Rectangle **rectangles, int *size, int index) {
    // Увеличиваем массив для нового элемента
    *rectangles = resizeArray(*rectangles, *size + 1);
    for (int i = *size; i > index; --i) {
        (*rectangles)[i] = (*rectangles)[i - 1]; // Сдвиг элементов
    }
    printf("Вставка нового прямоугольника на индекс %d:\n", index);
    inputRec(&(*rectangles)[index]); // Ввод данных для прямоугольника
    (*size)++;
}

// Удаление прямоугольника по индексу
void removeRecIn(Rectangle **rectangles, int *size, int index) {
    for (int i = index; i < *size - 1; ++i) {
        (*rectangles)[i] = (*rectangles)[i + 1]; // Сдвиг элементов
    }
    (*size)--;

    *rectangles = resizeArray(*rectangles, *size); // Уменьшение размера массива
    printf("Прямоугольник на индексе %d удален.\n", index);
}

// Удаление всех прямоугольников
void removeAll(Rectangle **rectangles, int *size) {
    free(*rectangles);       // Освобождение памяти
    *rectangles = NULL;      // Обнуление указателя
    *size = 0;               // Сброс размера массива
    printf("Все прямоугольники удалены.\n");
}

// Вывод данных одного прямоугольника
void printRec(Rectangle rectangle) {
    printf("Длина: %.0f;\nШирина: %.0f;\nПлощадь: %.0f;\nОриентация: %c.\n", rectangle.length, rectangle.width, rectangle.length * rectangle.width, orientation(rectangle.length, rectangle.width));
}

// Вывод всех прямоугольников
void printAll(Rectangle *rectangles, int size) {
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
void printRecIn(Rectangle *rectangles, int size, int index) {
    if (index >= 0 && index < size) {
        printf("Прямоугольник на индексе %d:\n", index);
        printRec(rectangles[index]);
    } else {
        printf("Неверный индекс.\n");
    }
}

void saveInFile(Rectangle *rectangles, int size) {
    char name[256];

    printf("Введите название файла: ");
    scanf("%s", name);

    FILE *file = fopen(name, "w");

    if (!file) {
        printf("Ошибка при открытии файла\n");
        return;
    }

    for (int i = 0; i < size; i++) {
        fprintf(file, "%.2f %.2f\n", rectangles[i].length, rectangles[i].width);
    }

    fclose(file);
    printf("Данные сохранены!\n");
}

void readFromFile(Rectangle **rectangles, int *size) {
    char name[256];

    printf("Введите название файла: ");
    scanf("%s", name);

    FILE *file = fopen(name, "r");

    if (!file) {
        printf("Ошибка при открытии файла\n");
        return;
    }

    int count = 0;
    Rectangle temp;
    // Сначала считываем, сколько прямоугольников можно будет загрузить
    while (fscanf(file, "%lf %lf", &temp.length, &temp.width) == 2) {
        count++;
        *rectangles = resizeArray(*rectangles, count); // Увеличиваем размер массива для каждого нового прямоугольника
        (*rectangles)[count - 1] = temp; // Сохраняем прочитанные данные
    }

    *size = count; // Обновляем текущий размер
    fclose(file);
    printf("Успешно загружены данные.\n");
}

void sortAll(Rectangle *rectangles, int size) {
    qsort(rectangles, size, sizeof(Rectangle), compare);
}
