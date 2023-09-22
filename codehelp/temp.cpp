#include<iostream>
#include <vector>
#include "../gfg/array/default_funcs.cpp"
using namespace std;

// find unique element in array where  other elements are repwated exactly twice
int findUnique1(int arr[], int n)
{
    int uniq = 0;
    for(int i = 0; i < n; i++)
    {
        uniq = uniq ^ arr[i];
    }
    return uniq;
}

vector <int> find2Uniques(int arr[], int n)
{
    int uniq = 0;
    for(int i = 0; i < n; i++)
    {
        uniq = uniq ^ arr[i];
    }

    vector<int> ans;
    int a = uniq, b= uniq;
    for(int i = 0; i < n; i++)
    {
        if(arr[i]&1)
        {
            a = a^arr[i];
        }
    }
    ans.push_back(a);
    b = a ^ uniq;
    ans.push_back(b);

    return ans;
}

int findDuplicate1(int arr[], int n)
{
    int dupl = 0;
    for(int i = 0; i < n; i++)
    {
        dupl = dupl ^ arr[i];
    }
    for(int i= 1; i < n; i++)
    {
        dupl = dupl^i;
    }
    return dupl;
}


int main()
{
    int arr1[9] = {4, 4, 2, 4, 4, 5, 5, 9, 9};
    
    int uniq = findUnique1(arr1, 9);
    cout << " unique -> "<< uniq << endl;

    int arr2[9] = {1, 2, 3, 4, 5, 6, 7, 8, 8};
    int dupl = findDuplicate1(arr2, 9);
    cout << " dupl -> "<< dupl << endl;   // wrong

    int arr3[8] = {1, 1, 2, 3, 4, 4, 5, 5};
    vector<int> uniques = find2Uniques(arr3, 8);
    printVector(uniques);
    
}