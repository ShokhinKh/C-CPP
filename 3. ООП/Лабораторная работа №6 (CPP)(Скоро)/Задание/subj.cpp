#include "subj.hpp"
#include <iostream>
#include <cstring>
#include <limits>

using namespace std;

// Конструкторы
Base::Base() { // избавляюсь от того, что уже не канон 
    name[0] = '\0';
    habitat[0] = '\0';
    temperature = 0;
    humidity = 0;
    lifespan = 0;
    reproductiveAge = 0;
}

Plant::Plant() {
    plantType[0] = '\0';
    reproduction[0] = '\0';
    hasFruits = false;
}

Fish::Fish() {
    waterType[0] = '\0';
}

Bird::Bird() {
    avgEggCount = 0;
    canFly = false;
    canFloat = false;
    canDive = false;
}

Animal::Animal()  {
    foodType[0] = '\0';
}

// Диспетчеризация для Base::Print
// void Base::Print() const {
//     switch (type) {
//         case ItemType::itPlant:
//             static_cast<const Plant*>(this)->Print();
//             break;
//         case ItemType::itFish:
//             static_cast<const Fish*>(this)->Print();
//             break;
//         case ItemType::itBird:
//             static_cast<const Bird*>(this)->Print();
//             break;
//         case ItemType::itAnimal:
//             static_cast<const Animal*>(this)->Print();
//             break;
//         default:
//             cout << "Неизвестный тип объекта!" << endl;
//     }
// }          Эту штуку надо поменять, так как надо чтоб полиморфизм был


// реализация этого метода
int Base::Compare(const Base* other) const {
    return strcoll(this->name, other->name);
}


// Методы ввода для каждого класса
void Plant::Input() {
    SafeInputString("Введите название: ", name, 50);
    SafeInputString("Введите среду обитания: ", habitat, 100);
    temperature = SafeInputFloat("Введите температуру: ");
    humidity = SafeInputFloat("Введите влажность: ");
    lifespan = SafeInputInt("Введите продолжительность жизни: ", 0, 500);
    reproductiveAge = SafeInputInt("Введите репродуктивный возраст: ", 0, lifespan);
    
    SafeInputString("Введите тип растения: ", plantType, 30);
    SafeInputString("Введите способ размножения: ", reproduction, 40);
    hasFruits = SafeInputInt("Имеет плоды (1 - да, 0 - нет): ", 0, 1);
}

void Fish::Input() {
    SafeInputString("Введите название: ", name, 50);
    SafeInputString("Введите среду обитания: ", habitat, 100);
    temperature = SafeInputFloat("Введите температуру: ");
    humidity = SafeInputFloat("Введите влажность: ");
    lifespan = SafeInputInt("Введите продолжительность жизни: ", 0, 500);
    reproductiveAge = SafeInputInt("Введите репродуктивный возраст: ", 0, lifespan);
    
    SafeInputString("Введите тип воды (Пресная/соленая): ", waterType, 10);
}

void Bird::Input() {
    SafeInputString("Введите название: ", name, 50);
    SafeInputString("Введите среду обитания: ", habitat, 100);
    temperature = SafeInputFloat("Введите температуру: ");
    humidity = SafeInputFloat("Введите влажность: ");
    lifespan = SafeInputInt("Введите продолжительность жизни: ", 0, 500);
    reproductiveAge = SafeInputInt("Введите репродуктивный возраст: ", 0, lifespan);
    
    avgEggCount = SafeInputInt("Среднее количество кладки яиц: ", 0, 100);
    canFly = SafeInputInt("Может летать (1 - да, 0 - нет): ", 0, 1);
    canFloat = SafeInputInt("Может плавать (1 - да, 0 - нет): ", 0, 1);
    canDive = SafeInputInt("Умеет нырять под воду (1 - да, 0 - нет): ", 0, 1);
}

void Animal::Input() {
    SafeInputString("Введите название: ", name, 50);
    SafeInputString("Введите среду обитания: ", habitat, 100);
    temperature = SafeInputFloat("Введите температуру: ");
    humidity = SafeInputFloat("Введите влажность: ");
    lifespan = SafeInputInt("Введите продолжительность жизни: ", 0, 500);
    reproductiveAge = SafeInputInt("Введите репродуктивный возраст: ", 0, lifespan);
    
    SafeInputString("Чем питается (Травоядный/Хищник/Всеядный): ", foodType, 30);
}

// Методы вывода для каждого класса
void Plant::Print() const {
    cout << "Название: " << name << endl;
    cout << "Место обитания: " << habitat << endl;
    cout << "Температура: " << temperature << endl;
    cout << "Влажность: " << humidity << endl;
    cout << "Продолжительность жизни: " << lifespan << endl;
    cout << "Репродуктивный возраст: " << reproductiveAge << endl;
    
    cout << "Вид растения: " << plantType << endl;
    cout << "Метод размножения: " << reproduction << endl;
    cout << "Имеет плоды?: " << (hasFruits ? "Yes" : "No") << endl;
}

void Fish::Print() const {
    cout << "Название: " << name << endl;
    cout << "Место обитания: " << habitat << endl;
    cout << "Температура: " << temperature << endl;
    cout << "Влажность: " << humidity << endl;
    cout << "Продолжительность жизни: " << lifespan << endl;
    cout << "Репродуктивный возраст: " << reproductiveAge << endl;
    
    cout << "Тип воды: " << waterType << endl;
}

void Bird::Print() const {
    cout << "Название: " << name << endl;
    cout << "Место обитания: " << habitat << endl;
    cout << "Температура: " << temperature << endl;
    cout << "Влажность: " << humidity << endl;
    cout << "Продолжительность жизни: " << lifespan << endl;
    cout << "Репродуктивный возраст: " << reproductiveAge << endl;
    
    cout << "Среднее количество яиц: " << avgEggCount << endl;
    cout << "Может летать?: " << (canFly ? "Yes" : "No") << endl;
    cout << "Может плавать?: " << (canFloat ? "Yes" : "No") << endl;
    cout << "Может нырять?: " << (canDive ? "Yes" : "No") << endl;
}

void Animal::Print() const {
    cout << "Название: " << name << endl;
    cout << "Место обитания: " << habitat << endl;
    cout << "Температура: " << temperature << endl;
    cout << "Влажность: " << humidity << endl;
    cout << "Продолжительность жизни: " << lifespan << endl;
    cout << "Репродуктивный возраст: " << reproductiveAge << endl;
    
    cout << "Вид питания: " << foodType << endl;
}

// Методы SubjList
void SubjList::PrintAll() const {
    if (!head) {
        cout << "Список пуст." << endl;
        return;
    }

    Item *current = head;
    while (current) {
        static_cast<Base*>(current)->Print();
        cout << endl;
        current = current->next;
    }
}

void SubjList::SortByName() {
    if (!head) return;

    bool swapped;
    do {
        swapped = false;
        Item *current = head;

        while (current && current->next) {
            Base *a = static_cast<Base*>(current);
            Base *b = static_cast<Base*>(current->next);

            if (a->Compare(b) > 0) { // это все переписываю
                // Обмен элементами
                if (current->prev) {
                    current->prev->next = current->next;
                } else {
                    head = current->next;
                }

                if (current->next->next) {
                    current->next->next->prev = current;
                } else {
                    tail = current;
                }

                current->next->prev = current->prev;
                current->prev = current->next;
                current->next = current->next->next;
                current->prev->next = current;

                swapped = true;
            } else {
                current = current->next;
            }
        }
    } while (swapped);
}

void SubjList::FindByLifespan(int minLife, int maxLife) const {
    if (!head) {
        cout << "Список пуст." << endl;
        return;
    }

    bool found = false;
    Item *current = head;

    while (current) {
        Base *obj = static_cast<Base*>(current);
        int life = obj->GetLifespan();
        if (life >= minLife && life <= maxLife) {
            obj->Print();
            cout << endl;
            found = true;
        }
        current = current->next;
    }

    if (!found) {
        cout << "Не найдено объектов в указанном диапазоне." << endl;
    }
}

// Функции безопасного ввода
int SafeInputInt(const char *prompt, int minValue, int maxValue) {
    int value;
    while (true) {
        cout << prompt;
        if (cin >> value && value >= minValue && value <= maxValue) {
            cin.ignore();
            return value;
        }
        cout << "Ошибка: Введите число от " << minValue << " до " << maxValue << "!" << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

float SafeInputFloat(const char *prompt) {
    float value;
    while (true) {
        cout << prompt;
        if (cin >> value) {
            cin.ignore();
            return value;
        }
        cout << "Ошибка: Введите корректное число!" << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

void SafeInputString(const char *prompt, char *destination, int maxLength) {
    char buffer[256];
    while (true) {
        cout << prompt;
        if (cin.getline(buffer, sizeof(buffer))) {
            if (strlen(buffer) <= (size_t)maxLength) {
                strncpy(destination, buffer, maxLength);
                return;
            }
            cout << "Ошибка: Максимальная длина - " << maxLength << " символов!" << endl;
        } else {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}