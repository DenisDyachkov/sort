#include <iostream>
#include <cmath>

using namespace std;

int karatsuba(int x, int y) {
    int n = max(to_string(x).length(), to_string(y).length());
    int m = n / 2;

    int high1 = x / pow(10, m);
    int low1 = x % (int)pow(10, m);
    int high2 = y / pow(10, m);
    int low2 = y % (int)pow(10, m);

    int z0 = karatsuba(low1, low2);
    int z1 = karatsuba(low1 + high1, low2 + high2);
    int z2 = karatsuba(high1, high2);

    return z2 * pow(10, 2 * m) + (z1 - z2 - z0) * pow(10, m) + z0;
}

int main() {
    int x = 12;
    int y = 32;

    cout <<  karatsuba(x, y) << endl;

    return 0;
}