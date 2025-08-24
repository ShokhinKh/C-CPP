#include <stdlib.h>
#include <stdio.h>

typedef struct item {
    struct item *next;
    struct item *prev;
} Item;

typedef struct {
    Item *head;
    Item *tail;
} List;

// ДОбавление элемента в конец списка
void add(List *list, Item *item);

//Подсчет количества элементов в списке 
int count(const List *list);

//Возвращает индекс элемента item из списка list
int GetIndex(const List *list, const Item *item);

//Возвращает элемент по индексу n из списка list
Item* GetItem(const List *list, const int n);

// Удаляет элемент по индексу 
Item* Remove(List *list, const int n);

//Удаляет из списка элемент по индексу
void Delete(List *list, const int n);

//Очищение списка
void clear(List *list);

//вставка элемента по индексу 
void insert(List *list, Item *item, const int n);

//Вывод списка
void listout(const List *list);

//меню
void menu();

//Возвращает введённое целочисленное значение
int input(char *msg);

//Выделяет память под элемент
int create_item(Item **item);

void print_item(Item *item);

int entry(List *list);

int main() {

    system("chcp 65001 > NUL");
    
    List list = {
        NULL,
        NULL
    };

    while(entry(&list));

    return 0;
}

// ДОбавление элемента в конец списка
void add(List *list, Item *item) {
    if (list && item) {
        if (list->head == NULL && list->tail == NULL) {
            list->head = item; 
            list->tail = item;
            item->next = NULL;
            item->prev = NULL; 
        } else {
            item->prev = list->tail;
            list->tail->next = item;
            item->next = NULL;
            list->tail = item;
        }
    }
}


//Подсчет количества элементов 
int count(const List *list) {
    int cnt = 0;

    if (list) {
        Item *item = list->head;
        
        while (item) {
            cnt++;
            item = item->next;
        }
    }

    return cnt;
}

//Возвращает индекс элемента item из списка list
int GetIndex(const List *list, const Item *item) {
    if (!list || !item) return -1;

    Item *temp = list->head;
    int i = 0;

    while (temp) {
        if (temp == item) {
            return i;
        }
        i++;
        temp = temp->next;
    }

    return -1;
}

//Возвращает элемент по индексу n из списка list
Item* GetItem(const List *list, const int n) {
    Item *item = NULL;

    if (list) {
        item = list->head;
        int i = 0;

        while (item && n != i) {
            i++;
            item = item->next;
        }
    }

    return item;
}

// Удаляет элемент по индексу 
Item* Remove(List *list, const int n) {
    if (!list || n < 0) return NULL;

    Item* result = GetItem(list, n);
    if (!result) return NULL;

    if (list->head == list->tail) { // Один элемент
        list->head = NULL;
        list->tail = NULL;
    } else if (list->head == result) { // Первый элемент
        list->head = result->next;
        list->head->prev = NULL;
    } else if (list->tail == result) { // Последний элемент
        list->tail = result->prev;
        list->tail->next = NULL;
    } else { // Элемент где-то в середине
        result->prev->next = result->next;
        result->next->prev = result->prev;
    }

    return result;
}

//Удаляет из списка элемент по индексу
void Delete(List *list, const int n) {
    if (list) {
        Item *item = Remove(list, n);
        if (item) {
            free(item);
        }
    }
}

//Очищение списка
void clear(List *list) {
    if (list) {
        while (list->head) {
            Delete(list, 0);
        }

        list->head = NULL;
        list->tail = NULL;
    }
}

//вставка элемента по индексу 
void insert(List *list, Item *item, const int n) {
    if (list && item) {
        
        Item *temp = GetItem(list, n);
        
        if (list->head == NULL && list->tail == NULL || !temp) {
            add(list, item); // Добавить элемент в конец
        } else if (temp == list->head) { 
            // Вставка в начало списка
            item->next = list->head;
            item->prev = NULL; 
            list->head->prev = item; 
            list->head = item; 
        } else {
            // Вставка в середину или в конец списка
            item->prev = temp->prev;
            item->next = temp;
            temp->prev->next = item;
            temp->prev = item; 
        }
    }
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

//Выделяет память под элемент
int create_item(Item **item) {
    int code = 0;

    *item = calloc(1, sizeof(Item));
    if (!item) {
        code = 1;
    }

    return code;
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
            printf("Memory allocation error! Please try again\n");
        }
        break;
    case 3:
        if (!create_item(&item)) {
            listout(list);
            printf("Элемент для вставки: %p\n", item);
            n = input("Введите индекс для вставки: ");
            insert(list, item, n);
            // cls();
            listout(list);
        } else {
            printf("Memory allocation error! Please try again\n");
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
            // cls();
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