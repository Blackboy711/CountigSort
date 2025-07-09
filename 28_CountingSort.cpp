#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
void fillArr(int** arr, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            arr[i][j] = rand() % 10;
        }
    }
}
int findMax(int arr[], int size) { 
    int max_val = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max_val) {
            max_val = arr[i];
        }
    }
    return max_val;
}
void countingSortRow(int arr[], int size) {
    int max_val = findMax(arr, size); 
    int* count = new int[max_val + 1]();
    int* output = new int[size];
    for (int i = 0; i < size; i++) {
        count[arr[i]]++;
    }
    for (int i = 1; i <= max_val; i++) {
        count[i] += count[i - 1];
    }
    for (int i = size - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }
    for (int i = 0; i < size; i++) {
        arr[i] = output[i];
    }
    delete[] count;
    delete[] output;
}
void one(int** Arr, int n, int m, int* arr) {
    int k = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            arr[k++] = Arr[i][j];
        }
    }
}
void doublee(int** Arr, int n, int m, int* arr) {
    int k = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            Arr[i][j] = arr[k++];
        }
    }
}
void sortRows(int** Arr, int n, int m) {
    for (int i = 0; i < n; i++) {
        countingSortRow(Arr[i], m);
    }
}
void showArr(int** arr, int n, int m) {
    for (int i = 0; i < n; i++) {
        cout << endl;
        for (int j = 0; j < m; j++) {
            cout << arr[i][j] << ' ';
        }
    }
    cout << endl;
}
int main() {
    setlocale(LC_ALL, "RU");
    const int n = 5, m = 5;
    srand(time(NULL));
    int** Arr = new int* [n];
    for (int i = 0; i < n; i++) {
        Arr[i] = new int[m];
    }
    int* arr = new int[n * m];
    fillArr(Arr, n, m);
    cout << "Невідсортована матриця:";
    showArr(Arr, n, m);
    sortRows(Arr, n, m);
    cout << "Матриця, відсортована по рядках:";
    showArr(Arr, n, m);
    one(Arr, n, m, arr);
    countingSortRow(arr, n * m);
    doublee(Arr, n, m, arr);
    cout << "Повністю відсортована матриця:";
    showArr(Arr, n, m);
    delete[] arr;
    for (int i = 0; i < n; i++) {
        delete[] Arr[i];
    }
    delete[] Arr;
    return 0;
}
