#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

void insertionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int main() {
    const int size = 10000;
    vector<int> arr(size);

    srand(time(0));
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100000;  
    }

    cout << "ishodny massiv:\n";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
        if (i % 20 == 19) cout << "\n";  
    }
    cout << "\n\n";

    insertionSort(arr);

    cout << "otsortirovany massiv:\n";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
        if (i % 20 == 19) cout << "\n";  
    }
    cout << "\n";

    return 0;
}
