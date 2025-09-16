#include <iostream>
#include "subj.hpp"

using namespace std;

int main() {
    system("chcp 65001 > nul");
    
    SubjList database;
    
    int choice;
    do {
        // Вывод меню
        cout << "\n--- База данных станции юных натуралистов ---" << endl;
        cout << "1. Добавить растение" << endl;
        cout << "2. Добавить рыбу" << endl;
        cout << "3. Добавить птицу" << endl;
        cout << "4. Добавить животное" << endl;
        cout << "5. Вывести всех" << endl;
        cout << "6. Отсортировать по названию" << endl;
        cout << "7. Найти по продолжительности жизни" << endl;
        cout << "8. Очистить базу" << endl;
        cout << "9. Выход" << endl;
        cout << "-----------------------------------------" << endl;
        
        choice = SafeInputInt("Выберите действие: ", 1, 9);
        
        switch (choice) {
            case 1: { // Добавить растение
                Plant *newPlant = new Plant();
                newPlant->Input();
                database.add(newPlant);
                cout << "Растение добавлено в базу!" << endl;
                break;
            }
            
            case 2: { // Добавить рыбу
                Fish *newFish = new Fish();
                newFish->Input();
                database.add(newFish);
                cout << "Рыба добавлена в базу!" << endl;
                break;
            }
            
            case 3: { // Добавить птицу
                Bird *newBird = new Bird();
                newBird->Input();
                database.add(newBird);
                cout << "Птица добавлена в базу!" << endl;
                break;
            }
            
            case 4: { // Добавить животное
                Animal *newAnimal = new Animal();
                newAnimal->Input();
                database.add(newAnimal);
                cout << "Животное добавлено в базу!" << endl;
                break;
            }
            
            case 5: { // Вывести всех
                cout << "\n=== Содержимое базы данных ===" << endl;
                database.PrintAll();
                break;
            }
            
            case 6: { // Сортировать по названию
                database.SortByName();
                cout << "База отсортирована по названию." << endl;
                cout << "\n=== Отсортированная база ===" << endl;
                database.PrintAll();
                break;
            }
            
            case 7: { // Поиск по продолжительности жизни
                int minLife = SafeInputInt("Введите минимальную продолжительность жизни: ", 0, 1000);
                int maxLife = SafeInputInt("Введите максимальную продолжительность жизни: ", minLife, 1000);
                
                cout << "\n=== Результаты поиска (" << minLife << " - " << maxLife << ") ===" << endl;
                database.FindByLifespan(minLife, maxLife);
                break;
            }
            
            case 8: { // Очистить базу
                database.clear();
                cout << "База данных очищена." << endl;
                break;
            }
            
            case 9: { // Выход
                cout << "Выход из программы..." << endl;
                break;
            }
            
            default:
                cout << "Неизвестный пункт меню!" << endl;
                break;
        }
        
    } while (choice != 9);
    database.clear();
    
    return 0;
}