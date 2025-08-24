/*

Вариант №17

База данных станции юных натуралистов должна содержать информацию о растениях, рыбах, птицах, животных. 
Для всех указывается наименование, ареал обитания, температура содержания и влажность, время жизни в годах 
(для рыб - в днях или годах) и репродуктивный возраст. Для растений также указывается тип (трава, кустарник и т.п.), 
способ размножения и наличие плодов; для рыб - тип воды (соленая или пресная); для птиц - среднее количество яиц в кладке, 
умение летать, плавать на поверхности воды и под водой; для животных - тип корма. Необходимо реализовать сортировку по названию и 
поиск по времени жизни, заданному в виде диапазона. 

*/






#include "subj.h"

// Массив строк для типов объектов
const char * const TypeName[] = {
    "Фиг знает", "Растение", "Рыба", "Птица", "Животное"
};

//функция создания объекта
Base *Create(ItemType type) {
    Base *obj = NULL;
    switch (type) {
        case itPlant:
            obj = (Base *)calloc(1, sizeof(Plant));
            break;
        case itFish:
            obj = (Base *)calloc(1, sizeof(Fish));
            break;
        case itBird:
            obj = (Base *)calloc(1, sizeof(Bird));
            break;
        case itAnimal:
            obj = (Base *)calloc(1, sizeof(Animal));
            break;
        default:
            printf("Неизвестный тип!\n");
    }
    if (obj) {
        obj->type = type;
    }
    return obj;
}

// Функция ввода данных
void Input(Base *obj) {
    if (!obj) return;

    SafeInputString("Введите название: ", obj->name, 50);
    SafeInputString("Введите среду обитания: ", obj->habitat, 100);
    obj->temperature = SafeInputFloat("Введите температуру: ");
    obj->humidity = SafeInputFloat("Введите влажность: ");
    obj->lifespan = SafeInputInt("Введите продолжительность жизни: ", 0, 500);
    obj->reproductiveAge = SafeInputInt("Введите репродуктивный возраст: ", 0, obj->lifespan);

    // Ввод специфических данных
    switch (obj->type) {
        case itPlant: {
            Plant *plant = (Plant *)obj;
            SafeInputString("Введите тип растения: ", plant->plantType, 30);
            SafeInputString("Введите способ размножения: ", plant->reproduction, 40);
            plant->hasFruits = SafeInputInt("Имеет плоды (1 - да, 0 - нет): ", 0, 1);
            break;
        }
        case itFish: {
            Fish *fish = (Fish *)obj;
            SafeInputString("Введите тип воды (Пресная/соленая): ", fish->waterType, 10);
            break;
        }
        case itBird: {
            Bird *bird = (Bird *)obj;
            bird->avgEggCount = SafeInputInt("Среднее количество кладки яиц: ", 0, 100);
            bird->canFly = SafeInputInt("Может летать (1 - да, 0 - нет): ", 0, 1);
            bird->canFloat = SafeInputInt("Может плавать (1 - да, 0 - нет): ", 0, 1);
            bird->canDive = SafeInputInt("Умеет нырять под воду (1 - да, 0 - нет): ", 0, 1);
            break;
        }
        case itAnimal: {
            Animal *animal = (Animal *)obj;
            SafeInputString("Чем питается (Травоядный/Хищник/Всеядный): ", animal->foodType, 30);
            break;
        }
        default:
            printf("Неизвестный тип объекта!\n");
    }
}


// Функция печати объекта
void Print(const Base *obj) {
    if (!obj) return;

    printf("Название: %s\n", obj->name);
    printf("Место обитания: %s\n", obj->habitat);
    printf("Температура: %.2f\n", obj->temperature);
    printf("Влажность: %.2f\n", obj->humidity);
    printf("Продолжительность жизни: %d\n", obj->lifespan);
    printf("Репродуктивный возраст: %d\n", obj->reproductiveAge);

    switch (obj->type) {
        case itPlant: {
            Plant *plant = (Plant *)obj;
            printf("Вид расстения: %s\n", plant->plantType);
            printf("Метод размножения: %s\n", plant->reproduction);
            printf("Имеет плоды?: %s\n", plant->hasFruits ? "Yes" : "No");
            break;
        }
        case itFish: {
            Fish *fish = (Fish *)obj;
            printf("Тип воды: %s\n", fish->waterType);
            break;
        }
        case itBird: {
            Bird *bird = (Bird *)obj;
            printf("Среднее количество яиц: %d\n", bird->avgEggCount);
            printf("Может летать?: %s\n", bird->canFly ? "Yes" : "No");
            printf("Может плавать?: %s\n", bird->canFloat ? "Yes" : "No");
            printf("Может нырять?: %s\n", bird->canDive ? "Yes" : "No");
            break;
        }
        case itAnimal: {
            Animal *animal = (Animal *)obj;
            printf("Вид питания: %s\n", animal->foodType);
            break;
        }
        default:
            printf("Неизвестный тип!\n");
    }
}

// Функция печати списка
void PrintList(const List *list) {
    if (!list || !list->head) {
        printf("Список пуст.\n");
        return;
    }

    Item *p = list->head;
    while (p) {
        Print((Base *)p);
        p = p->next;
        printf("\n");
    }
}

// Функция сортировки списка по названию
void SortList(List *list) {
    if (!list || !list->head) return; // Проверка на пустоту списка

    int swapped;
    do {
        swapped = 0;
        Item *current = list->head;

        while (current && current->next) {
            Base *a = (Base *)current;
            Base *b = (Base *)current->next;

            // Сравнение имен по локали
            if (strcoll(a->name, b->name) > 0) {
                // Меняем элементы местами, корректируя ссылки
                Item *next = current->next;

                current->next = next->next;
                if (next->next) {
                    next->next->prev = current;
                }

                next->prev = current->prev;
                if (current->prev) {
                    current->prev->next = next;
                } else {
                    list->head = next;
                }

                next->next = current;
                current->prev = next;

                // Если это был последний элемент, обновляем "tail"
                if (!current->next) {
                    list->tail = current;
                }

                swapped = 1;
            } else {
                current = current->next;
            }
        }
    } while (swapped);
}


// Поиск по времени жизни
void FindByLifespan(const List *list, int minLife, int maxLife) {
    if (!list || !list->head) {
        printf("Список пуст.\n");
        return;
    }

    int found = 0;
    Item *current = list->head;

    while (current) {
        Base *obj = (Base *)current;
        if (obj->lifespan >= minLife && obj->lifespan <= maxLife) {
            Print(obj); // Печатаем подходящий объект
            found = 1;
        }
        current = current->next;
    }

    if (!found) {
        printf("Не найдено объектов в указанном диапазоне продолжительности жизни.\n");
    }
}

void RunProgram(List *list) {
    const char *menu[] = {
        "Добавить элементы",
        "Вывести элементы",
        "Найти по продолжительности жизни",
        "Сортировка по имени",
        "Выход"
    };

    while (1) {
        printf("\n--- Меню ---\n");
        for (int i = 0; i < 5; i++) {
            printf("%d. %s\n", i + 1, menu[i]);
        }

        int choice = SafeInputInt("> Ваш выбор: ", 1, 5);

        switch (choice) {
            case 1: {
                // Добавить элемент
                printf("\nВыберите тип объекта:\n");
                for (int i = 1; i <= 4; i++) {
                    printf("%d. %s\n", i, TypeName[i]);
                }

                int type = SafeInputInt("> Тип объекта: ", 1, 4);
                ItemType selectedType = (ItemType)type;
                Base *newObject = Create(selectedType);

                if (newObject) {
                    Input(newObject);
                    add(list, (Item *)newObject);
                } else {
                    printf("Ошибка создания объекта.\n");
                }
                break;
            }

            case 2: {
                // Вывести список элементов
                PrintList(list);
                break;
            }

            case 3: {
                // Найти по продолжительности жизни
                int minLife = SafeInputInt("Введите минимальную продолжительность жизни: ", 0, 1000);
                int maxLife = SafeInputInt("Введите максимальную продолжительность жизни: ", minLife, 1000);

                printf("Объекты с продолжительностью жизни от %d до %d:\n", minLife, maxLife);
                FindByLifespan(list, minLife, maxLife);
                break;
            }

            case 4: {
                // Сортировать список и вывести
                SortList(list);
                printf("\nСписок отсортирован по имени:\n");
                PrintList(list);
                break;
            }

            case 5:
                // Очистить список и выйти
                clear(list);
                printf("Выход из программы...\n");
                return;

            default:
                printf("Ошибка: неверный выбор. Попробуйте снова.\n");
                break;
        }
    }
}


// Безопасный ввод целого числа с проверкой
int SafeInputInt(const char *prompt, int minValue, int maxValue) {
    int value;
    char buffer[100];
    int isValid = 0;

    do {
        printf("%s", prompt);
        if (fgets(buffer, sizeof(buffer), stdin)) {
            if (sscanf(buffer, "%d", &value) == 1 && value >= minValue && value <= maxValue) {
                isValid = 1;
            } else {
                printf("Ошибка: Введите число в диапазоне [%d - %d]!\n", minValue, maxValue);
            }
        }
    } while (!isValid);

    return value;
}

// Безопасный ввод числа с плавающей точкой
float SafeInputFloat(const char *prompt) {
    float value;
    char buffer[100];
    int isValid = 0;

    do {
        printf("%s", prompt);
        if (fgets(buffer, sizeof(buffer), stdin)) {
            if (sscanf(buffer, "%f", &value) == 1) {
                isValid = 1;
            } else {
                printf("Ошибка: Введите корректное число!\n");
            }
        }
    } while (!isValid);

    return value;
}


// Безопасный ввод строки
void SafeInputString(const char *prompt, char *destination, int maxLength) {
    char buffer[256];
    int isValid = 0;

    do {
        printf("%s", prompt);
        if (fgets(buffer, sizeof(buffer), stdin)) {
            // Удаляем символ новой строки
            buffer[strcspn(buffer, "\n")] = 0;

            if (strlen(buffer) <= (size_t)maxLength) {
                strncpy(destination, buffer, maxLength);
                isValid = 1;
            } else {
                printf("Ошибка: Максимальная длина строки — %d символов. Попробуйте снова.\n", maxLength);
            }
        }
    } while (!isValid);
}