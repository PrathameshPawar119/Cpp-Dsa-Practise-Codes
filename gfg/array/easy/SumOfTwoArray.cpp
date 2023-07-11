#include <iostream>
#include "../default_funcs.cpp"
#include <vector>
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
int sumTwoArraysByCarry(int arr1[], int m, int arr2[], int n)
{
    int i = 0, j = 0;
    int carry = 0;
    vector <int> ans;
    
    while(i<m && j<n)
    {
        int sum = arr1[m-i-1]+arr2[n-j-1]+carry;
        ans.push_back(sum%10);
        carry = sum >= 10 ? 1 : 0;
        i++; j++;
    }

    while(i<m)
    {
        int sum = arr1[m-i-1]+carry;
        ans.push_back(sum%10);
        carry = 0;
        i++;
    }

    while(j<n)
    {
        int sum = arr2[n-j-1]+carry;
        ans.push_back(sum%10);
        carry = 0;
        j++;
    }

    // printVector(ans);
    int temp = 0;
    for(int i = ans.size()-1; i >= 0; i--)
    {
        int digit = ans[i];
        temp = temp*10 + digit;
    }

    return temp;
}

int main()
{
    int arr1[3] = {5, 1, 2};
    int arr2[6] = {1, 0, 0, 0, 0, 0};

    // sumTwoArrays(arr1, 4, arr2, 1);
    cout <<"sumTwoArraysByCarry(arr1, 4, arr2, 1)-> "<< sumTwoArraysByCarry(arr1, 3, arr2, 6);



}