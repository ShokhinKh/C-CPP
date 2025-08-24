#include "Interface.h"

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

//Выделяет память под элемент
int create_item(Item **item) {
    int code = 0;

    *item = calloc(1, sizeof(Item));
    if (!item) {
        code = 1;
    }

    return code;
}