#include<iostream>
#include<math.h>
using namespace std;

int decimalToBinary(int n){
    int ans = 0;
    int i = 0;
    while (n != 0)
    {    
        int bit = n & 1;
        ans = (bit * pow(10, i)) + ans;
        n = n >> 1;
        i++;
    }
    return ans;
}

int binaryToDecimal(int n){
    int ans = 0;
    int i= 0;
    while (n != 0)
    {
        int digit = n%10;
        ans = digit*pow(2,i)+ans;
        i++;
        n /= 10;
    }
    return ans;
}

int reverseNumber(int n){
    int ans = 0;
    while (n != 0)
    {
        int digit = n%10;
        ans = ans * 10 + digit;
        n /= 10;
    }
    return ans;
 }

char flip(char n){
     if(n== '0')
    {
        return '1';
    }
    return '0';
}

void onesComplement(string bin){
    int n_len = bin.length();
    string ones;
    for (int i = 0; i < n_len; i++)
    {
        ones += flip(bin[i]);
    }
    cout << ones << endl;
}

int complementOfNumber(int n){
    int mask = 0;
    int m = n;
    while (m != 0)
    {
        mask = (mask << 1) | 1;
        m = m >> 1;
    }
    int ans = ~n & mask;
    return ans;
}

int recFactorial(int n){
    if (n == 1 || n == 0)
    {
        return 1;
    }
    return n*recFactorial(n-1);
}

bool isPrime(int n){
    if (n == 1 || n % 2 == 0)
        return 0;
    if (n == 2)
        return 1;
    for (long i = 2; i <= sqrt(n); i += 2)
    {
        if (n % i == 0)
            return 0;
    }
    return 1;
}

int countPrimes(int n) {
    int primes = 0;
    for (int i = 2; i < (n); i++)
    {
        if(isPrime(i)){
            primes++;
        }
    }
    return primes;
}

int update(int n){
    int a = n*2;
    return a;
}

int main(){
    cout << decimalToBinary(5) << endl;
    cout << binaryToDecimal(9) << endl;
    cout << reverseNumber(1234) << endl;
    onesComplement("10101");
    cout << complementOfNumber(5) << endl;
    cout << recFactorial(4) << endl;
    cout << countPrimes(10) << endl;

    int n = 10;
    cout << update(n) << endl;
    cout << n << endl;
}