#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdlib>
#include <ctime>

#define MIN -50
#define MAX 50
#define d 5

using namespace std;

// Функция для вывода массива
void output(double array[], int size) {
    for (int i = 0; i < size; i++) {
        cout << array[i];
        if (i + 1 != size) {
            cout << ", "; 
        }
    }
    cout << endl;
}


void ascending_order(double array[], int size) {
    double step = static_cast<double>(MAX - MIN) / size;
    for (int i = 0; i < size; i++) {
        array[i] = MIN + i * step;
    }
}

void descending_order(double array[], int size) {
    double step = static_cast<double>(MAX - MIN) / size;
    for (int i = 0; i < size; i++) {
        array[i] = MAX - i * step;
    }
}

void random_order(double array[], int size) {
    for (int i = 0; i < size; i++) {
        array[i] = MIN + rand() % (MAX - MIN + 1);
    }
}

void sawtooth(double array[], int size) {
    int interval = size / d;
    double step = static_cast<double>(MAX - MIN) / interval;
    for (int i = 0; i < size; i++) {
        array[i] = MIN + step * (i % interval);
    }
}

void stepwise(double array[], int size) {
    int interval = size / d;
    for (int i = 0; i < size; i++) {
        array[i] = MIN + (MAX - MIN) * (i / interval) / d;
    }
}

void sinus(double array[], int size) {
    double amplitude = static_cast<double>(MAX - MIN) / 2;
    for (int i = 0; i < size; i++) {
        double x = (2 * M_PI * i) / size;
        array[i] = MIN + amplitude * (sin(x) + 1);
    }
}

void mix(double array[], int size) {
    double step = static_cast<double>(MAX - MIN) / (size / d);
    for (int i = 0; i < size; i++) {
        array[i] = MIN + step * (i / d) + sin(i * (M_PI * 2 / d)) * step / 2;
    }
}


double measure_time(void (*func)(double[], int), double *arr, int size) {
    clock_t start = clock();
    func(arr, size);
    clock_t end = clock();
    return static_cast<double>(end - start) / CLOCKS_PER_SEC;
}


void runAll(int size) {
    double array[size] = {0};

    cout << "Упорядоченная:" << endl;
    ascending_order(array, size);
    output(array, size); // Вывод массива

    cout << "Упорядоченная в обратном порядке:" << endl;
    descending_order(array, size);
    output(array, size);

    cout << "Рандом:" << endl;
    random_order(array, size);
    output(array, size);

    cout << "Пилообразная:" << endl;
    sawtooth(array, size);
    output(array, size);

    cout << "Ступенчатая:" << endl;
    stepwise(array, size);
    output(array, size);

    cout << "Синусоидальная:" << endl;
    sinus(array, size);
    output(array, size);

    cout << "Квази:" << endl;
    mix(array, size);
    output(array, size);
}

void test_time(double array[], int size) {
    double ascending_time = measure_time(ascending_order, array, size);
    double descending_time = measure_time(descending_order, array, size);
    double random_time = measure_time(random_order, array, size);
    double sawtooth_time = measure_time(sawtooth, array, size);
    double stepwise_time = measure_time(stepwise, array, size);
    double sinus_time = measure_time(sinus, array, size);
    double mix_time = measure_time(mix, array, size);

    cout << endl << "Время выполнения:" << endl;
    cout << "  Упорядоченная: " << ascending_time << " сек" << endl;
    cout << "  Упорядоченная в обратном порядке: " << descending_time << " сек" << endl;
    cout << "  Рандом: " << random_time << " сек" << endl;
    cout << "  Пилообразная: " << sawtooth_time << " сек" << endl;
    cout << "  Ступенчатая: " << stepwise_time << " сек" << endl;
    cout << "  Синусоидальная: " << sinus_time << " сек" << endl;
    cout << "  Квази: " << mix_time << " сек" << endl;
}

int main() {
    system("chcp 65001 > nul"); 

    int size = 10 * pow(10, 5);


    double *array = new double[size];

    // runAll(size);
    test_time(array, size);
   

    delete[] array;
    return 0;
}
