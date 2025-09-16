#include "List.hpp"

// Добавление элемента в конец списка
void List::add(Item *item) {
    if (item) {
        if (head == nullptr && tail == nullptr) {
            head = item; 
            tail = item;
            item->next = nullptr;
            item->prev = nullptr; 
        } else {
            item->prev = tail;
            tail->next = item;
            item->next = nullptr;
            tail = item;
        }
    }
}

// Подсчет количества элементов 
int List::count() const {
    int cnt = 0;
    Item *item = head;
    
    while (item) {
        cnt++;
        item = item->next;
    }
    return cnt;
}

// Возвращает индекс элемента item из списка
int List::getIndex(const Item *item) const {
    if (!item) return -1;

    Item *temp = head;
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

// Возвращает элемент по индексу n из списка
Item* List::getItem(int n) const {
    Item *item = head;
    int i = 0;

    while (item && i < n) {
        i++;
        item = item->next;
    }
    return item;
}

// Удаляет элемент по индексу 
Item* List::remove(int n) {
    if (n < 0) return nullptr;

    Item* result = getItem(n);
    if (!result) return nullptr;

    if (head == tail) { // Один элемент
        head = nullptr;
        tail = nullptr;
    } else if (head == result) { // Первый элемент
        head = result->next;
        head->prev = nullptr;
    } else if (tail == result) { // Последний элемент
        tail = result->prev;
        tail->next = nullptr;
    } else { // Элемент где-то в середине
        result->prev->next = result->next;
        result->next->prev = result->prev;
    }

    return result;
}

// Удаляет из списка элемент по индексу
void List::deleteItem(int n) {
    Item *item = remove(n);
    if (item) {
        delete item;
    }
}

// Очищение списка
void List::clear() {
    while (head) {
        deleteItem(0);
    }
    head = nullptr;
    tail = nullptr;
}

// Вставка элемента по индексу 
void List::insert(Item *item, int n) {
    if (!item) return;
    
    if (head == nullptr && tail == nullptr) {
        add(item);
        return;
    }

    Item *temp = getItem(n);
    if (!temp) {
        add(item); // Добавить элемент в конец
        return;
    }

    if (temp == head) { 
        // Вставка в начало списка
        item->next = head;
        item->prev = nullptr; 
        head->prev = item; 
        head = item; 
    } else {
        // Вставка в середину
        item->prev = temp->prev;
        item->next = temp;
        temp->prev->next = item;
        temp->prev = item; 
    }
}