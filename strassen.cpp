#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
//дяя нод
long long gcd(long long a, long long b) {
    while (b != 0) {
        long long t = b;
        b = a % b;
        a = t;
    }
    return a;
}


int jacobi(long long a, long long n) {
    if (a == 0) return 0;
    if (a == 1) return 1;

    int result = 1;
    while (a > 1) {
        if (a % 2 == 0) {
            a /= 2;
            if (n % 8 == 3 || n % 8 == 5) {
                result = -result;
            }
        } else {
            if (a % 4 == 3 && n % 4 == 3) {
                result = -result;
            }
            long long t = a;
            a = n % a;
            n = t;
        }
    }
    return result;
}

//для модуля
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


bool strassen_test(long long n) {
    if (n <= 1) return false;
    if (n <= 3) return true;  
    if (n % 2 == 0) return false; 
    
    srand(time(NULL));

    long long a = 2 + rand() % (n - 3); 
    long long g = gcd(a, n);
    if (g > 1) return false; 
    
    long long exponent = (n - 1) / 2;
    long long x = mod_exp(a, exponent, n);
    int jacobi_symbol = jacobi(a, n);

    return x == jacobi_symbol % n; 
}

int main() {
    long long n;

    cout << "Введите число для проверки на простоту: ";
    cin >> n;

    if (strassen_test(n)) {
        cout << n << " вероятно простое." << endl;
    } else {
        cout << n << " составное." << endl;
    }

    return 0;
}