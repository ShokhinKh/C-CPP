#include <iostream>
#include <cmath> 

using namespace std;

int serial(int A[], int Size, int item, int &n) {
    for (int i = 0; i < Size; i++ ) { 
        n++;
        if (A[i] == item) { 
            return i;
        }
    }
    return -1;
}

// Бинарный поиск
int binary(int* A, int Size, int item, int &n) {
    int Low = 0, High = Size - 1;
    while (Low <= High) {
        n++;
        int Pos = (Low + High) / 2; 
        if (item < A[Pos]) {
            High = Pos - 1;
        } else if (item > A[Pos]) {
            Low = Pos + 1;
        } else {
            return Pos; 
        }
    }
    return -1; 
}

// прыж поиск
int Jump(int a[], int n, int item, int &iterations) {
    int i = 0;
    int m = sqrt(n);
    cout << "m: " << m << endl;
    while (i < n && a[min(m, n) - 1] < item) { 
        iterations++;
        i = m;
        m += sqrt(n);
        if (i >= n) 
            return -1; 
    }

    for (int x = i; x < min(m, n); x++) {
        iterations++; 
        if (a[x] == item)
            return x; 
    }
    return -1;
}

int main() {

    system("chcp 65001 > nul"); 
    int size, item;
    cout << "Введите размер массива: ";
    cin >> size;
    
    int *array = new int[size];

    for (int i = 0; i < size; i++) { 
        array[i] = i;
    }

    cout << "Введите значение для поиска: ";
    cin >> item;

    int iterationsSerial = 0;
    int iterationsBinary = 0;
    int iterationsJump = 0;

    int posSerial = serial(array, size, item, iterationsSerial);
    int posBinary = binary(array, size, item, iterationsBinary);
    int posJump = Jump(array, size, item, iterationsJump);

    if (posSerial != -1) {
        cout << "Элемент найден в позиции (последовательный поиск): " << posSerial 
             << ". Итераций: " << iterationsSerial << endl;
    } else {
        cout << "Элемент не найден (последовательный поиск). Итераций: " 
             << iterationsSerial << endl;
    }

    if (posBinary != -1) {
        cout << "Элемент найден в позиции (бинарный поиск): " << posBinary 
             << ". Итераций: " << iterationsBinary << endl;
    } else {
        cout << "Элемент не найден (бинарный поиск). Итераций: " 
             << iterationsBinary << endl;
    }

    if (posJump != -1) {
        cout << "Элемент найден в позиции (Jump поиск): " << posJump 
             << ". Итераций: " << iterationsJump << endl;
    } else {
        cout << "Элемент не найден (Jump поиск). Итераций: " 
             << iterationsJump << endl;
    }

    delete[] array; 
    return 0;
}
