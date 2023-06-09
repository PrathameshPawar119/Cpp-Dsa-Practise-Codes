#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int n;
    cin >> n;

    // Finding Reverse of a number
    // int reverse = 0;
    // while (n > 0)
    // {
    //     int lastDigit = n%10;
    //     reverse = reverse*10 + lastDigit;
    //     n = n/10;
    // }
    // cout << reverse;

    //Checking Armstrong Number
    int total = 0;
    while (n > 0)
    {
        int lastDigit = n%10;
        total += pow(lastDigit,3);
        n = n/10;
    }
    cout <<  total;
    
    

}