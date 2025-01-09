#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

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


bool miller_test(long long n, int k) {
    if (n <= 1) return false; 
    if (n <= 3) return true;  
    if (n % 2 == 0) return false; 
    
 
    long long s = 0, d = n - 1;
    while (d % 2 == 0) {
        d /= 2;
        s++;
    }


    for (int i = 0; i < k; ++i) {
        long long a = 2 + rand() % (n - 3); 
        long long x = mod_exp(a, d, n);

        if (x == 1 || x == n - 1) continue; 
        
        
        for (int j = 0; j < s - 1; ++j) {
            x = mod_exp(x, 2, n);
            if (x == n - 1) break; 
        }

        if (x != n - 1) return false; 
    }
    return true; 
}


long long generate_random_number(int bit_length) {
    long long min = pow(2, bit_length - 1); 
    long long max = pow(2, bit_length) - 1; 

    return min + rand() % (max - min + 1);
}

// Генерация простого числа заданной битовой длины
long long generate_prime(int bit_length, int k) {
    srand(time(NULL));

    while (true) {
        long long candidate = generate_random_number(bit_length);


        if (candidate % 2 == 0) candidate++;

   
        if (miller_test(candidate, k)) {
            return candidate;
        }
    }
}

int main() {
    int bit_length;
    int k = 5; 

    cout << "Введите битовую длину простого числа: ";
    cin >> bit_length;

    long long prime = generate_prime(bit_length, k);
    cout << "Сгенерированное простое число: " << prime << endl;

    return 0;
}