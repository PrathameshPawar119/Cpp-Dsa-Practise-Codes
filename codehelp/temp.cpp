#include <iostream>
using namespace std;

int modFactorial(int n){
    int x = 1;
    for (int i = 2; i < n; i++)
    {
        x = (x*i);
    }
    return x;
    
}

int main(){
    cout << modFactorial(5) << endl ;
    cout << char('A' + 5);

    cout <<endl<< (0+5)/2;
    cout <<endl<< 2%4;

}