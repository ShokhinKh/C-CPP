#include "list.h"

Item::Item() : next(nullptr), prev(nullptr), owner(nullptr) {}

Item::~Item() {
    if(owner){
        owner->Remove(owner->GetIndex(this));
    }
}


List::List() : head(nullptr), tail(nullptr){}

List::~List() {
    Clear();
}

void List::Add(Item* item) {
    if (!item) return;

    item->owner = this;

    if (!head) {
        head = tail = item;
    } else {
        tail->next = item;
        item->prev = tail;
        tail = item;
    }
}

void List::Insert(Item* item, int index) {
    if (!item) return;

    item->owner = this;

    if (index == 0) { // Вставка в начало
        if (head) {
            item->next = head;
            head->prev = item;
        }
        head = item;
        if (!tail) tail = item;
        return;
    }

    // Вставка в середину
    Item* current = GetItem(index);
    if (!current) {
        Add(item);
        return;
    }

    // Вставка перед текущим элементом
    item->next = current;
    item->prev = current->prev;
    if (current->prev) {
        current->prev->next = item;
    }
    current->prev = item;
}

Item* List::Remove(int index) {
    Item* item = GetItem(index);
    if (!item) return nullptr;

    if (item == head) {
        head = item->Next();
        if (head) {
            head->prev = nullptr;
        } else {
            tail = nullptr;
        }
    } else if (item == tail) { 
        tail = item->Prev();
        if (tail) {
            tail->next = nullptr;
        } else {
            head = nullptr;
        }
    } else { 
        item->Prev()->next = item->Next();
        item->Next()->prev = item->Prev();
    }

    item->next = nullptr;
    item->prev = nullptr;
    item->owner = nullptr;

    return item;
}


void List::Delete(int index) {
    if (index < 0) throw std::out_of_range("Index is out of range.");

    Item* item = GetItem(index);
    if (!item) return;
    delete item;
}

void List::Clear() {
    while (head) {
        Delete(0);
    }
}

int List::Count() const {
    Item* current = head;
    int count = 0;
    while (current) {
        count++;
        current = current->next;
    }
    return count;
}

Item* List::GetItem(int index) const {
    if (index < 0) return nullptr;

    Item* current = head;
    int i = 0;
    while (current && i < index) {
        current = current->next;
        i++;
    }

    return current;
}


int List::GetIndex(Item *item){
    int i = 0;
    Item *temp = NULL;

    if (item) {
        temp = head;

        while (temp != item && temp) {
            i++;
            temp = temp->next;
        }
    }

    return (temp) ? i : -1;
}
