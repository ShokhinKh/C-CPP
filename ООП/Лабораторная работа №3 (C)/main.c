#include <stdio.h>
#include <stdlib.h>
#include "subj.h"
#include "interface.h" 


//Вывод списка
void listout(const List *list);

//меню
void menu();

//Возвращает введённое целочисленное значение
int input(char *msg);

void print_item(Item *item);

int entry(List *list);

int main() {

    system("chcp 65001 > NUL");
    
    List list = {
        NULL,
        NULL
    };

    RunProgram(&list); 

    // while(entry(&list));

    return 0;
}


//Вывод списка
void listout(const List *list) {

    if (!list) {
        printf("List is NULL.\n");
        return;
    }

    Item *item = list->head;
    int i = 0;

    printf("List: %p\tHead: %p\tTail: %p\n", list, list->head, list->tail);
    printf("№\tItem Address\t\tPrev Address\t\tNext Address\n");
    
    // Цикл по элементам списка
    while (item) {
        printf("%d\t%016p\t%016p\t%016p\n", i, item, item->prev, item->next);
        i++;
        item = item->next;
    }
}

//меню
void menu() {
    printf("1. Вывод всех элементов\n");
    printf("2. Добавление элемента\n");
    printf("3. Добавление элемента в любое место\n");
    printf("4. Подсчёт всех элементов\n");
    printf("5. Поиск элемента по индексу\n");
    printf("6. Удаление элемента из списка\n");
    printf("7. Полная очистка списка\n");
    printf("8. Выход из программы\n");
}

//Возвращает введённое целочисленное значение
int input(char *msg) {
    double buff = 0;
    char ch = '\0';
    int flag = 1;

    while (flag) {

        if (msg) {
            printf("%s", msg);
        }
        if (scanf("%lf", &buff) != 1 || buff - (int)buff != 0) {
            printf("Некорректный ввод, попробуй снова\n");
            while ((ch = getchar()) != '\n' && ch != EOF);
        } else {
            flag = 0;
        }
    }  

    return (int)buff;
}

void print_item(Item *item) {
    if (!item) {
        printf("Пустой элемент\n");
    } else {
        printf("%p\t%p\n", item->prev, item->next);
    }
}

int entry(List *list) {
    int code = 1, choise = 0, n = 0;
    char ch = '\0';
    Item *item = NULL;

    menu();
    choise = input("Выбери пункт: ");

    switch (choise) {
    case 1:
        listout(list);
        break;
    case 2:
        if (!create_item(&item)) {
            add(list, item);
            printf("Элемент %p, добавлен в список\n", item);
        } else {
            printf("Ошибка выделения памяти! Пожалуйста, попробуйте снова\n");
        }
        break;
    case 3:
        if (!create_item(&item)) {
            listout(list);
            printf("Элемент для вставки: %p\n", item);
            n = input("Введите индекс для вставки: ");
            insert(list, item, n);
            listout(list);
        } else {
            printf("Ошибка выделения памяти! Пожалуйста, попробуйте снова\n");
        }
        break;
    case 4:
        printf("Количество элементов в списке: %d\n", count(list));
        break;
    case 5:
        listout(list);
        n = input("Введите n: ");
        print_item(GetItem(list, n));
        break;
    case 6:
        if (list->head != NULL && list->tail != NULL) {
            listout(list);
            n = input("Введите индекс элемента для удаления: ");
            Delete(list, n);    
            listout(list);
        } else {
            printf("Нет элементов для удаления\n");
        }
        break;
    case 7:
        if (list->head == NULL && list->tail == NULL) {
            printf("Список пуст!\n");
        } else {
            clear(list);
        }
        break;
    case 8:
        if (list->head != NULL && list->tail != NULL) {
            printf("Очистка списка перед выходом\n");
            clear(list);
        }
        code = 0;
        break;
    default:
        printf("Такого пункта меню нет, попробуй снова\n");
        break;
    }

    return code;
}