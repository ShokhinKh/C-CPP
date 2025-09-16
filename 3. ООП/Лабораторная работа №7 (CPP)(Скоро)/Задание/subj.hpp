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
// protected:
    // ItemType type; уже не надо 
public:
    char name[50];
    char habitat[100];
    float temperature;
    float humidity;
    int lifespan;
    int reproductiveAge;

    Base();
    virtual ~Base() = default;

    virtual void Input() = 0;
    virtual void Print() const = 0; 
    virtual ItemType GetType() const = 0; // добавил эту штуку 

    virtual int Compare(const Base* other) const; // и эту
    virtual const char* GetName() const { return name; }
    virtual int GetLifespan() const { return lifespan; }


    //Штука для сравнениия с объектами
    bool operator>(const Base& other) const;
    bool operator<(const Base& other) const;


    //Штука для сравнениия с интами
    bool operator>=(int value) const;
    bool operator<=(int value) const;
    bool operator==(int value) const;


};

class Plant : public Base {
public:
    char plantType[30];
    char reproduction[40];
    bool hasFruits;

    Plant();
    void Input() override;
    void Print() const override;

    ItemType GetType() const override { return ItemType::itPlant; } //везде переопределяю виртуальную функцию эту, оверрайд некий
};

class Fish : public Base {
public:
    char waterType[10];

    Fish();
    void Input() override;
    void Print() const override;

    ItemType GetType() const override { return ItemType::itFish; } //везде переопределяю виртуальную функцию эту, оверрайд некий
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

    ItemType GetType() const override { return ItemType::itBird; } //везде переопределяю виртуальную функцию эту, оверрайд некий
};

class Animal : public Base {
public:
    char foodType[30];

    Animal();
    void Input() override;
    void Print() const override;

    ItemType GetType() const override { return ItemType::itAnimal; } //везде переопределяю виртуальную функцию эту, оверрайд некий
};

class SubjList : public List {
public:
    void PrintAll() const;
    void SortByName();
    void FindByLifespan(int minLife, int maxLife) const;

    Base& operator[](int index); // то что меняется 
    const Base& operator[](int index) const; // то что не меняется 
};

// Объявления функций безопасного ввода
int SafeInputInt(const char *prompt, int minValue, int maxValue);
float SafeInputFloat(const char *prompt);
void SafeInputString(const char *prompt, char *destination, int maxLength);

#endif // SUBJ_HPP