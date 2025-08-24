#include <iostream>
#include <cstring>   // Для strlen, strstr
#include <fstream>
#include <chrono>    // Для измерения времени

using namespace std;

#define S 119
#define d 256

// Алгоритм Рабина-Карпа
int SubStringRK(char T[], int N, char P[], int M) {
    int h = 1;
    int p = 0;
    int t = 0;

    for (int i = 0; i < M - 1; i++) 
        h = (d * h) % S;

    for (int i = 0; i < M; i++) {
        p = (d * p + P[i]) % S;
        t = (d * t + T[i]) % S;
    }

    for (int i = 0; i <= N - M; i++) {
        if (p == t) {
            int j = 0;
            while (j < M && P[j] == T[i + j])
                j++;

            if (j == M)
                return i; // Подстрока найдена
        }
        if (i < N - M) {
            t = (d * (t - h * T[i]) + T[i + M]) % S;
            if (t < 0) t += S;
        }
    }
    return -1; // Подстрока не найдена
}

int main() {
    system("chcp 65001 > nul"); // Установка кодировки UTF-8 для консоли

    // Открываем файл
    ifstream infile("example.txt");

    if (!infile) {
        cerr << "Не удалось открыть файл.\n";
        return 1;
    }

    // Получаем размер файла
    infile.seekg(0, ios::end);
    size_t size = infile.tellg();
    infile.seekg(0, ios::beg);

    // Читаем содержимое файла
    char* text = new char[size + 1]; 
    infile.read(text, size);
    text[size] = '\0';
    infile.close();

    char pattern[] = "EVREYEBANIY";  
    int N = strlen(text);
    int M = strlen(pattern);

    // Поиск алгоритмом Рабина-Карпа
    auto start = chrono::high_resolution_clock::now();
    int resultRK = SubStringRK(text, N, pattern, M);
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed_seconds_RK = end - start;

    cout << "\n=== Поиск с помощью алгоритма Рабина-Карпа ===" << endl;
    if (resultRK != -1)
        cout << "Подстрока найдена по индексу: " << resultRK << endl;
    else
        cout << "Подстрока не найдена." << endl;
    cout << "Время выполнения: " << elapsed_seconds_RK.count() << " секунд." << endl;

    // Поиск с использованием strstr
    start = chrono::high_resolution_clock::now();
    char* strstr_result = strstr(text, pattern);
    end = chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed_seconds_strstr = end - start;

    cout << "\n=== Поиск с использованием функции strstr ===" << endl;
    if (strstr_result) {
        int index = strstr_result - text; // Вычисляем индекс найденной подстроки
        cout << "Подстрока найдена по индексу: " << index << endl;
    } else {
        cout << "Подстрока не найдена." << endl;
    }
    cout << "Время выполнения: " << elapsed_seconds_strstr.count() << " секунд." << endl;

    // Освобождаем память
    delete[] text;

    return 0;
}
