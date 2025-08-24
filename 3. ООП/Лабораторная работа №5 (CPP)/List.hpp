#ifndef LIST_H
#define LIST_H


class Item {
    public: 
        Item *next;
        Item *prev;
        Item() : next(nullptr), prev(nullptr) {}
        virtual ~Item() {}
};

class List {
    public: 
        Item *head;
        Item *tail;
        List() : head(nullptr), tail(nullptr) {}
        void add(Item *item);
    
        int count() const;
        int getIndex(const Item *item) const;
        Item* getItem(int n) const;
        Item* remove(int n);
        void deleteItem(int n);
        void clear();
        void insert(Item *item, int n);
};

#endif //LIST_H