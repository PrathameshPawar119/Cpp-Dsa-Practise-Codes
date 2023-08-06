#include <bits/stdc++.h>
using namespace std;

// Given an array of N integers where each value represents
// the number of chocolates in a packet. Each packet can have a variable number of chocolates.
// There are m students, the task is to distribute chocolate packets such that: 
// Each student gets one packet.
// The difference between the number of chocolates in the packet with maximum chocolates and the packet with minimum chocolates given to the students is minimum.
int findMinDiff(int arr[], int size, int m)
{
    sort(arr, arr + size);
    int min = INT_MAX;
    if(size < m)
    {
        return -1;
    }

    for(int i=0; i+m-1 < size; i++)
    {
        int diff = arr[i+m-1] - arr[i];
        if(diff < min)
        {
            min = diff;
        }
    }

    return min;
}

// int findMaxDiff(int arr[], int size, int m)
// {
    // sort(arr, arr+size);
    // int max = INT_MIN;
    // if(size <m)
    // {
    //     return -1;
    // }

    // for(int i=0; i+m-1 < size; i++)
    // {
    //     int diff = arr[i+m-1];
    //     if(diff > max)
    //     {
    //         max= diff;
    //     }
    // }

    // return max;
// }


int main()
{
    int arr[7] = {10, 20, 30, 40, 50, 60};
    int n = sizeof(arr)/sizeof(arr[0]);
    int m = 3;

    cout << findMinDiff(arr, n, m) << endl;

    // int arr2[4] = {5, 5, 5, 5};
    // cout <<findMaxDiff(arr2, 4, 2 );
}