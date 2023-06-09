#include <iostream>
#include <cmath>
using namespace std;

int RecFact(int n){
    if (n==0 || n==1)
    {
        return 1;
    }
    else
    {
        return n*RecFact(n-1);
    }   
}
int IteFact(int n){
    int temp = 1;
    for (int i = 0; i < n; i++)
    {
        temp += temp*i;
    }
    return temp;
}

int isPrime(int n){
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n%i == 0)
        {
            return false;
            break;
        }
    } 
    return true;
}

int PrimeBetwn(int a, int b){
    for (int i = a; i < b; i++)
    {
        if(isPrime(i)){
            cout << i << " ";
        }
    }
    return 0;
}

int fibo(int n){
    int t1 = 0;
    int t2 = 1;
    int nextT;
    for (int i = 0; i < n; i++)
    {
        cout << t1 << " ";
        nextT = t1+t2;
        t1 = t2;
        t2 = nextT;
    }
    return 0;
}

int ncr(int n, int r){
    return IteFact(n)/(IteFact(r)*IteFact(n-r));
}

int main(){
    cout << RecFact(5) << endl;
    cout << IteFact(5) << endl;

    PrimeBetwn(1,50);
    cout <<endl;

    fibo(6);


    int a = 7;
    for (int i = 0; i <= a; i++)
    {
        for (int j = 0; j < a-i; j++)
        {
            cout << "  ";
        }
        for (int j = 0; j <= i; j++)
        {
            cout << " " << ncr(i,j) << " ";
        }
        cout << endl;
    }
    
}