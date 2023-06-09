#include <iostream>
#include "../default_funcs.cpp"
using namespace std;

void sumTwoArrays(int arr1[], int m, int arr2[], int n)
{

    // converting array to numbers
    int num1 = 0, num2 = 0;
    for(int i=0; i<m; i++)
    {
        num1 = num1*10 + arr1[i];
    }
    for(int i=0; i<n; i++)
    {
        num2 = num2*10 + arr2[i];
    }

    // add numbers
    int temp = num1+num2;

    int max = m > n ? m : n;
    int ans[max];

    // again number to array
    int i = max-1;
    while(temp)
    {
        int digit = temp%10;
        ans[i--] = digit;
        temp /= 10;
    }
 

    printArray(ans, max);
}

// By using carry method
void sumTwoArrays2(int arr1[], int m, int arr2[], int n)
{
    int i = m-1;
    int j = n-1;
    int carry = 0;

}

int main()
{
    int arr1[4] = {1, 2, 3, 4};
    int arr2[1] = {6};

    sumTwoArrays(arr1, 4, arr2, 1);
    sumTwoArrays2(arr1, 4, arr2, 1);


}