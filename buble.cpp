// пузырьковая сортировка
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;


void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    bool swapped;
    for (int i = 0; i < n - 1; i++) {
        swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) {
            break;
        }
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

    
    bubbleSort(arr);

    cout << "otsort massiv:\n";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
        if (i % 20 == 19) cout << "\n";  
    }
    cout << "\n";

    return 0;
}
