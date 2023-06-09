#include <iostream>
#include <math.h>

using namespace std;

int verticalNumberPolygon(int a, int b){
    int i = a;
    while( i <= b){
        int j = a;
        while (j <= b)
        {
            cout << j << " ";
            //cout <<  b-j+1<< " "; // reverse
            j++;
        }
        cout << "\n";
        i++;
    }
    return 0;
}

int continousNumberSquare(int n){
    int i = 1;
    while (i <= n*n)
    {
        cout << i << " ";
        if (i % n == 0)
        {
            cout << "\n";
        }
        i++;
    }
    return 0;
}

int continousNumberTriangle(int n){
    int i = 1;
    while (i <= n)
    {
        int j = 1;
        int count = i;
        while (j <= i)
        {
            cout << count++ <<" ";
            j++;
        }
        cout << "\n";
        i++;
    }
    return 0;
}

int continousNumberTiangle2(int n){
    int i = 1;
    while (i <= n)
    {
        int j = i;
        while (2*i > j)
        {
            cout << j++ << " ";
        }
        cout << "\n";
        i++;
    }
    return 0;
}

int reverseNumberTriangle(int n){
    int i = 1;
    while (i <= n)
    {
        int j = 1;
        while (j <= i)
        {
            cout << i-j+1 << " ";
            j++;
        }
        i++;
        cout << "\n";
    }
    return 0;
}

int charSquare(int n){
    int i = 1;
    while (i <= n)
    {
        int j = 1;
        while (j <= n)
        {
            char ch = 'A'+i-1;
            cout << ch << " ";
            j++;
        }
        i++;
        cout << endl;
    }
    return 0;
}

int continousCharSquare(int n){
    int i = 1;
    char ch = 'A';
    while (i <= n)
    {   int j = 1;
        while (j <= n)
        {
            cout << char(ch+i+j-2)  << " ";
            j++;
        }
        i++;
        cout << endl;
    }
    return 0;
}

int sameRowCharTriangle(int n){
    int i = 1;
    while (i <= n)
    {
        int j = 1;
        while (j <= i)
        {
            char ch = 'A'+i-1;
            cout << ch << " ";
            j++;
        }
        i++;
        cout << endl;
    }
    return 0;
}

int reverseContinousCharTriangle(int n){
    int i = 1;
    char ch = 'A';
    while (i <= n)
    {
        int j = 1;
        while (j <= i)
        {
            cout << char(ch-i+j+n-1) << " ";
            j++;
        }
        i++;
        cout << endl;
    }
    return 0;
}

int regularNumberPyramid(int n){
    int  i = 1;
    while (i <= n)
    {
        int j = n-1;
        while (j >= i)
        {
            cout << "  ";
            j--;
        }
        j= 1;
        while (j <= i)
        {
            cout << j << " ";
            j++;
        }
        j = 2;
        while (j <= i)
        {
            cout << i-j+1 << " ";
            j++;
        }
        i++;
        cout<<endl;
    }
    return 0;
}

int dabbangPattern(int n){
    int i = 1;
    while (i <= n)
    {
        int j = n-1;
        while (j >= i)
        {
            cout << " * ";
            j--;
        }
        j = 1;
        while (j <= i)
        {
            cout <<" "<< j << " ";
            j++;
        }
        j = 2;
        while (j <= i)
        {
            cout <<" "<< i-j+1<<" ";
            j++;
        }
        j = n-1;
        while (j >= i)
        {
            cout <<" * ";
            j--;
        }
        
        i++;
        cout <<endl;
    }
    
    return 0;
}

// 0,1,1,2,3,5,8,13
int fibonacciNumbers(int n){
    int sum = 0;
    int a = 0;
    int b = 1;
    for (int i = 0; i <= n; i++)
    {   
        sum = a+b;
        cout << sum <<" ";
        a = b;
        b = sum;
    }
    return 0;
}

int isPrime(int n){
    bool isprime;
    for (int i = 2; i < sqrt(n); i++)
    {
        if (n%i == 0)
        {
            break;
            isprime = false;
        }
        else{
            isprime = true;
        }
    }
    return isprime;
}


int main(){

    verticalNumberPolygon(1, 4);
    cout << "\n";
    continousNumberSquare(3);
    cout << "\n";
    continousNumberTriangle(5);
    cout << "\n";
    continousNumberTiangle2(5);
    cout << "\n";
    reverseNumberTriangle(5);
    cout << "\n";
    charSquare(4);
    cout << "\n";
    continousCharSquare(4);
    cout << "\n";
    sameRowCharTriangle(4);
    cout << "\n";
    reverseContinousCharTriangle(4);
    cout << "\n";
    regularNumberPyramid(4);
    cout << "\n";
    dabbangPattern(4);
    cout << "\n";
    fibonacciNumbers(4);
    cout << "\n";
    cout << isPrime(2);

    return 0;
}