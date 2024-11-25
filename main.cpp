// быстрая сортировка
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];  
    int i = (low - 1);  

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] <= pivot) {
            i++;  
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    const int size = 10000;
    vector<int> arr(size);

    srand(time(0));
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100000;  // больше делать не вижу смысла
    }

    cout << "ishodny massiv:\n";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
        if (i % 20 == 19) cout << "\n";  
    }
    cout << "\n\n";

    quickSort(arr, 0, size - 1);

    cout << "otsortirovany massiv:\n";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
        if (i % 20 == 19) cout << "\n";  
    }
    cout << "\n";

    return 0;
}
