#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;


long long mod_exp(long long base, long long exp, long long mod) {
    long long result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

// Тест Ферма с одним случайным значением a
bool fermat_test_single(long long n) {
    if (n <= 1) return false; 
    if (n <= 3) return true;  
    if (n % 2 == 0) return false; 

    srand(time(NULL));

    long long a = 2 + rand() % (n - 3); 
    return mod_exp(a, n - 1, n) == 1; 
}

int main() {
    long long n;

    cout << "Введите число для проверки на простоту: ";
    cin >> n;

    if (fermat_test_single(n)) {
        cout << n << " вероятно простое." << endl;
    } else {
        cout << n << " составное." << endl;
    }

    return 0;
}