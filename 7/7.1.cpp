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

void bubbleSort(int* arr, int n) {
    double comparisonsAmount = 1;
    double movementsAmount = 0;

    for (int i = 0; i < n; i++)
    {
        comparisonsAmount += 2;

        for (int j = 0; j < n - 1; j++)
        {
            comparisonsAmount += 2;

            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                movementsAmount++;
            }
        }
    }

    cout << "Comparisons amount: " << comparisonsAmount << endl;
    cout << "Movements amount: " << movementsAmount << endl;
}

int main()
{
    int n = 10000;

    int* arr;
    createArr(arr, n);

    fillRandom(arr, n);

    clock_t start1 = clock();
    bubbleSort(arr, n);
    clock_t end1 = clock();

    double duration1 = (double)(end1 - start1) / CLOCKS_PER_SEC * 1000;
    cout << "Time taken: " << duration1 << " milliseconds" << endl << endl;
}
