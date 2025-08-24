
//Если честно, я уже не помню что тут, но предыдущие проблемы решены были оказывается.

#include "list.h"
#include <iostream>
#include <Windows.h>

class DebugList : public List {
public:
    void Menu();
    void Print();
};

void DebugList::Menu() {
    std::cout << "Меню:\n";
    std::cout << "1. Вывод всех элементов\n";
    std::cout << "2. Добавление элемента\n";
    std::cout << "3. Добавление элемента в любое место\n";
    std::cout << "4. Подсчёт всех элементов\n";
    std::cout << "5. Поиск элемента по индексу\n";
    std::cout << "6. Удаление элемента из списка\n";
    std::cout << "7. Полная очистка списка\n";
    std::cout << "8. Выход из программы\n";
}

void DebugList::Print() {
    Item* item = Head();
    int index = 0;
        std::cout << "id\tAddress\tPrev\tNext\n";
        while (item) {
            std::cout << index << '\t' 
                      << item << '\t' 
                      << item->Prev() << '\t' 
                      << item->Next() << '\n';
            item = item->Next();
            index++;
        }
}

int main() {
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
    DebugList list;
    char choice;
    bool running = true;

    while (running) {
        list.Menu();
        std::cin >> choice;

        switch (choice) {
            case '1': // Вывод всех элементов
                list.Print();
                break;
            case '2': // Добавление элемента
                list.Add(new Item());
                std::cout << "Элемент добавлен.\n";
                break;
            case '3': // Добавление элемента в любое место
                {
                    int index;
                    std::cout << "Введите индекс для вставки: ";
                    std::cin >> index;
                    list.Insert(new Item(), index);
                    std::cout << "Элемент вставлен.\n";
                }
                break;
            case '4': // Подсчет количества элементов
                std::cout << "Количество элементов: " << list.Count() << "\n";
                break;
            case '5': // Поиск элемента по индексу
                {
                    int index;
                    std::cout << "Введите индекс: ";
                    std::cin >> index;
                    Item* item = list.GetItem(index);
                    std::cout << "Элемент: " << item << ", Prev: " << item->Prev() 
                              << ", Next: " << item->Next() << "\n";
                }
                break;
            case '6': // Удаление элемента из списка
                {
                    int idx;
                    std::cout << "Введите индекс: ";
                    std::cin >> idx;
                    list.Remove(idx);
                    std::cout << "Элемент удален!\n";
                    break;
                }
            case '7': // Полная очистка списка
                list.Clear();
                std::cout << "Список полностью очищен.\n";
                break;
            case '8': // Выход
            std::cout << "Выход из программы.....\n";
                running = false;
                break;
            default:
                std::cout << "Мне твой выбор чет не нравится. Сильно не выпендривайся, выбери от 1 до 8.\n";
        }
    }

    return 0;
}
