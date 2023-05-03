#include <iostream>
#include <random>
#include <ctime>
#include <vector>

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

void shellSort(int* arr, int n) {
    long long comparisonsAmount = 1;
    long long movementsAmount = 1;

    vector<int> d;
    int i = 0;
    do {
        comparisonsAmount += 2;
        movementsAmount++;

        if (i % 2 == 0) {
            d.push_back(9 * pow(2, i) - 9 * pow(2, i / 2) + 1);
        }
        else {
            d.push_back(8 * pow(2, i) - 6 * pow(2, (i + 1) / 2) + 1);
        }
        i++;
    } while (d[d.size() - 1] * 3 <= n);

    int offsetInd = (d.size() > 1 ? d.size() - 2 : 0);
    movementsAmount += 2;

    while (offsetInd >= 0) {

        comparisonsAmount += 2;

        int offset = d[offsetInd--];
        movementsAmount++;

        for (int i = offset; i < n; i++) {
            comparisonsAmount += 2;

            int temp = arr[i];
            movementsAmount++;

            int j;

            for (j = i - offset; (j >= 0) && (arr[j] > temp); j -= offset) {
                comparisonsAmount += 2;
                arr[j + offset] = arr[j];
                movementsAmount++;
            }

            arr[j + offset] = temp;
            movementsAmount++;
        }
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
    shellSort(arr, n);
    clock_t end1 = clock();

    double duration1 = (double)(end1 - start1) / CLOCKS_PER_SEC * 1000;
    cout << "Time taken: " << duration1 << " milliseconds" << endl << endl;
    
}
