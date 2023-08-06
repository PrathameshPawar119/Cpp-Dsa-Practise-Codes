#include <iostream>
#include "../default_funcs.cpp"
using namespace std;

void revVec(vector<int>& vect)
{
    for(int i = 0; i < vect.size()/2; i++)
    {
        swap(vect[i], vect[vect.size()-i-1]);
    }
}

vector<int> multiplyArr(int arr[], int n, int m)
{
    vector<int> ans;
    int carry = 0, temp = 0, Q = 0;
    for(int i = n-1; i >= 0; i--)
    {
        temp = m*arr[i]+carry;
        ans.push_back(temp%10);
        Q = temp/10;
        carry = temp >= 10 ? Q : 0;
    }

    revVec(ans);
    return ans;
}

vector<int> LargaFactorial(int n)
{
    vector<int> ans = {1};
    for(int x = 2; x <= n; x++)
    {
        vector<int>pp;
        int car = 0, temp = 0;
        for(int i = ans.size()-1; i >= 0; i--)
        {
            temp = x * ans[i] + car;
            pp.push_back(temp%10);
            car = temp/10;
        } 
        while(car != 0)
        {
            pp.push_back(car%10);
            car /= 10;
        }
        revVec(pp);
        ans = pp;
    }

    return ans;
}

int main()
{
    int arr[3] = {1, 2, 0};
    int m = 6;
    // vector<int> ans = multiplyArr(arr, 3, m);
    vector<int> ans = LargaFactorial(100);
    printVector(ans);
}