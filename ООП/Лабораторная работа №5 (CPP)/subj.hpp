#ifndef SUBJ_HPP
#define SUBJ_HPP

#include "List.hpp"

enum class ItemType {
    itNone,
    itPlant,
    itFish,
    itBird,
    itAnimal
};

class Base : public Item {
protected:
    ItemType type;
public:
    char name[50];
    char habitat[100];
    float temperature;
    float humidity;
    int lifespan;
    int reproductiveAge;

    Base(ItemType t);
    virtual ~Base() {}

    virtual void Input() = 0;
    virtual void Print() const;

    virtual const char* GetName() const { return name; }
    virtual int GetLifespan() const { return lifespan; }
};

class Plant : public Base {
public:
    char plantType[30];
    char reproduction[40];
    bool hasFruits;

    Plant();
    void Input() override;
    void Print() const override;
};

class Fish : public Base {
public:
    char waterType[10];

    Fish();
    void Input() override;
    void Print() const override;
};

class Bird : public Base {
public:
    int avgEggCount;
    bool canFly;
    bool canFloat;
    bool canDive;

    Bird();
    void Input() override;
    void Print() const override;
};

class Animal : public Base {
public:
    char foodType[30];

    Animal();
    void Input() override;
    void Print() const override;
};

class SubjList : public List {
public:
    void PrintAll() const;
    void SortByName();
    void FindByLifespan(int minLife, int maxLife) const;
};

// Объявления функций безопасного ввода
int SafeInputInt(const char *prompt, int minValue, int maxValue);
float SafeInputFloat(const char *prompt);
void SafeInputString(const char *prompt, char *destination, int maxLength);

#endif // SUBJ_HPP