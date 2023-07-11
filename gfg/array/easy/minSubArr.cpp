#include <iostream>
using namespace std;

int minSubarraySum(int arr[], int n, int k) 
{
    
    int min = INT_MAX;
    // sort(arr, arr+n);

    for(int i=0; i+k-1<n; i++)
    {
        int temp = 0;
        for(int j=0; j<k; j++)
        {
            cout << arr[i+j]<<". ";
            temp += arr[i+j];
        }
        cout << temp<<endl;
        if(temp < min)
        {
            min = temp;
        }

    }

    return min;
}

int minSubarraySum2(int arr[], int n, int k)
{
    // cout<<endl;
    int temp = 0, min = 1000000;
    for(int j=0; j<k; j++)
    {
        temp += arr[j];
        // cout << arr[j] << " + ";
    }
    // cout <<" -> "<< temp << endl;

    int l = arr[0];
    int r = arr[k-1];

    for(int i=1; i+k-1<n; i++)
    {
        if(temp < min)
        {
            min = temp;
        }
        // cout << temp<<" + "<<arr[i+k-1]<<" - "<<arr[i-1];
        temp = temp+arr[i+k-1]-arr[i-1];
        // cout <<" -> "<< temp << endl;
    }

    return min;
}

int main()
{
    int arr[9] = {1, -4, 2, 10, -2, 3, 1, 0, -20};
    int n = 8, k = 4;
    cout <<"minSubarraySum(arr, n, k)-> "<< minSubarraySum2(arr, n, k);
}