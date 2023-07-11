#include <iostream>
#include <vector>
#include "../default_funcs.cpp"
using namespace std;

int substractTwoArraysByCarry(int arr1[], int m, int arr2[], int n)
{
    int sign = 1;
    if(n > m){
        swap(arr1, arr2);
        swap(m, n);
        sign = -1;
    }

    int i = 0, j = 0, carry = 0;
    vector <int> ans;

    while(i < m && j < n)
    {
        if(arr1[m-i-1] - arr2[n-j-1] < 0)
        {
            ans.push_back((arr1[m-i-1]+10-carry)-arr2[n-j-1]);
            carry = 1;
        }
        else{
            ans.push_back((arr1[m-i-1] - carry)-arr2[n-j-1]);
            carry = 0;
        }
        i++; j++;
    }

    while(i < m)
    {
        ans.push_back((arr1[m-i-1] - carry));
        carry = 0;
        i++;
    }

    int temp = 0;
    for(int i = ans.size()-1; i >= 0; i--)
    {
        int digit = ans[i];
        temp = temp*10 + digit;
    }

    return temp*sign;
}

int main()
{
    int arr1[7] = {1, 0, 2, 0, 4, 0, 0};
    int arr2[4] = {1, 2, 0, 0};

    cout << "substractTwoArraysByCarry -> "<< substractTwoArraysByCarry(arr1, 7, arr2, 4);
    // cout << "substractTwoArraysByCarry -> "<< substractTwoArraysByCarry(arr2, 4, arr1, 7);

}