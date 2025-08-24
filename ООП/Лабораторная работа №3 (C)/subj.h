#ifndef SUBJ_H
#define SUBJ_H

#include "Interface.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Перечисления объектов
typedef enum {
    itNone,
    itPlant,
    itFish,
    itBird,
    itAnimal
} ItemType;

// Массив строк для типов объектов
extern const char *const TypeName[];

// Базовая структура
typedef struct Base {
    Item base;
    ItemType type;
    char name[50];
    char habitat[100];
    float temperature;
    float humidity;
    int lifespan;
    int reproductiveAge;
} Base;

// Специфические структуры
typedef struct {
    Base base;
    char plantType[30];
    char reproduction[40];
    int hasFruits;
} Plant;

typedef struct {
    Base base;
    char waterType[10];
} Fish;

typedef struct {
    Base base;
    int avgEggCount;
    int canFly;
    int canFloat;
    int canDive;
} Bird;

typedef struct {
    Base base;
    char foodType[30];
} Animal;

// Фабрика объектов
Base *Create(ItemType type);
void Input(Base *obj);
void Print(const Base *obj);

// Функции работы со списком
void PrintList(const List *list);
void SortList(List *list);
void FindByLifespan(const List *list, int minLife, int maxLife);

// Основные действия, вызываемые из main.c
void RunProgram(List *list);




// Безопасный ввод целого числа с проверкой
int SafeInputInt(const char *prompt, int minValue, int maxValue);
// Безопасный ввод числа с плавающей точкой
float SafeInputFloat(const char *prompt);
// Безопасный ввод строки
void SafeInputString(const char *prompt, char *destination, int maxLength);

#endif // SUBJ_H
