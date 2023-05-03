#include <iostream>
#include <random>
#include <ctime>

using namespace std;

mt19937 rnd(time(0));

void createArr(int*& arr, int n) {
    arr = new int[n];
}

void fillRandom(int* arr, int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = rnd() % 100;
    }
}

void fillInc(int* arr, int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = i;
    }
}

void fillDec(int* arr, int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = n - i;
    }
}

long long comparisonsAmount = 0;
long long movementsAmount = 0;

void heapify(int arr[], int n, int i) {
    int largest = i; // Инициализируем наибольший элемент как корень
    int l = 2 * i + 1; // левый = 2*i + 1
    int r = 2 * i + 2; // правый = 2*i + 2
    movementsAmount += 3;
    comparisonsAmount += 3;
    // Если левый дочерний элемент больше корня
    if (l < n && arr[l] > arr[largest]) {
        largest = l;
        movementsAmount++;
    }
        

    // Если правый дочерний элемент больше, чем самый большой элемент на данный момент
    if (r < n && arr[r] > arr[largest]) {
        largest = r;
        movementsAmount++;
    }
        
    // Если самый большой элемент не корень
    if (largest != i) {
        swap(arr[i], arr[largest]);
        movementsAmount += 3;

        // Рекурсивно кучифицируем затронутое поддерево
        heapify(arr, n, largest);
    }
}

void heapSort(int* arr, int n) {
    // Построение кучи (перегруппируем массив)
    comparisonsAmount++;
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
        comparisonsAmount++;
    }
        

    // Один за другим извлекаем элементы из кучи
    comparisonsAmount++;
    for (int i = n - 1; i >= 0; i--) {
        // Перемещаем текущий корень в конец
        comparisonsAmount++;
        swap(arr[0], arr[i]);
        movementsAmount += 3;

        // вызываем процедуру heapify на уменьшенной куче
        heapify(arr, i, 0);
    }

    cout << "Comparisons amount: " << comparisonsAmount << endl;
    cout << "Movements amount: " << movementsAmount << endl;
    cout << "All: " << movementsAmount + comparisonsAmount << endl;
}


int main()
{
    int n = 1000000;

    int* arr;
    createArr(arr, n);

    fillRandom(arr, n);

    clock_t start1 = clock();
    heapSort(arr, n);
    clock_t end1 = clock();

    double duration1 = (double)(end1 - start1) / CLOCKS_PER_SEC * 1000;
    cout << "Time taken: " << duration1 << " milliseconds" << endl << endl;
}
