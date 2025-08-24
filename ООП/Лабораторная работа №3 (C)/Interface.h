#ifndef MY_INTERFACE_H 
#define MY_INTERFACE_H 

#include <stdlib.h>


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

//Выделяет память под элемент
int create_item(Item **item);

#endif