#include <iostream>
using namespace std;

int diffBetweenSumProduct(int n){
    int sum = 0;
    int product = 1;
    while (n != 0)
    {
        int a = n % 10;
        sum = sum + a;
        product = product*a;
        n = n/10;
    }
    
    return (product-sum);
}

int main(){
     cout << diffBetweenSumProduct(234);

}