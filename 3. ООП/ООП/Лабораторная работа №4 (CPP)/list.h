#ifndef LIST_H
#define LIST_H

#include <iostream>

// Forward declaration
class List;

class Item {
private:
    Item* next; // Указатель на следующий элемент
    Item* prev; // Указатель на предыдущий элемент
    List* owner; // Указатель на список, которому принадлежит элемент
    
public:
    Item(); // Конструктор
    ~Item(); // Деструктор

    // Доступ к указателям через методы
    Item* Next() const { return next; }
    Item* Prev() const { return prev; }

    // Позволяет классу List получать доступ к private-членам Item
    friend class List;
    
};

class List {
private:
    Item* head; // Указатель на первый элемент
    Item* tail; // Указатель на последний элемент



public:
    List(); // Конструктор
    ~List(); // Деструктор

    void Add(Item* item); // Добавляет элемент в конец списка
    void Insert(Item* item, int index); // Вставляет элемент по индексу
    void Delete(int index); // Удаляет элемент по индексу
    void Clear(); // Полностью очищает список
    int Count() const; // Подсчет количества элементов
    Item* GetItem(int index) const; // Возвращает элемент по индексу
    int GetIndex(Item *item); // Возвращает индекс элемента
    Item* Remove(int index); // Удаляет элемент по индексу
    // Методы доступа для начала и конца списка
    Item* Head() const { return head; }
    Item* Tail() const { return tail; }
};

#endif
