#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> fastSquare(const vector<int>& x, int base) {
    vector<int> reversedX = x;
    reverse(reversedX.begin(), reversedX.end());

    size_t n = reversedX.size();
    size_t resultSize = 2 * n;
    vector<int> y(resultSize, 0);

    for (size_t i = 0; i < n; ++i) {
        int carry = 0;

        int uv = y[2 * i] + reversedX[i] * reversedX[i];
        y[2 * i] = uv % base;
        carry = uv / base;

        for (size_t j = i + 1; j < n; ++j) {
            int cuv = y[i + j] + 2 * reversedX[i] * reversedX[j] + carry;
            y[i + j] = cuv % base;
            carry = cuv / base;
        }

        y[i + n] += carry;
    }

    while (y.size() > 1 && y.back() == 0) {
        y.pop_back();
    }

    reverse(y.begin(), y.end());
    return y;
}

void printNumber(const vector<int>& number) {
    for (int digit : number) {
        cout << digit;
    }
    cout << endl;
}

int main() {
    vector<int> x = {1, 2, 3};
    int base = 10;

     cout << "Исходное число: ";
    printNumber(x);

    vector<int> result = fastSquare(x, base);

    cout << "Результат возведения в квадрат:  ";
    printNumber(result);

    return 0;
}
