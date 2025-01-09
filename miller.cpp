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

bool miller_test(long long n) {
    if (n <= 1) return false; 
    if (n <= 3) return true;  
    if (n % 2 == 0) return false; 
    
   
    long long s = 0, d = n - 1;
    while (d % 2 == 0) {
        d /= 2;
        s++;
    }

    // Выполним один тест
    srand(time(NULL));
    long long a = 2 + rand() % (n - 3); 
    long long x = mod_exp(a, d, n);

    if (x == 1 || x == n - 1) return true; 


    for (int j = 0; j < s - 1; ++j) {
        x = mod_exp(x, 2, n);
        if (x == n - 1) return true; 
    }

    return false; 
}

int main() {
    long long n;

    cout << "Введите число для проверки на простоту: ";
    cin >> n;

    if (miller_test(n)) {
        cout << n << " вероятно простое." << endl;
    } else {
        cout << n << " составное." << endl;
    }

    return 0;
}