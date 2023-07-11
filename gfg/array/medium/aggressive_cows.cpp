#include <iostream>
#include <algorithm>
using namespace std;

// Given a sorted array arr[] consisting of N integers
//  which denote the position of a stall. You are also 
//  given an integer K which denotes the number of 
//  aggressive cows. You are given the task of assigning
//   stalls to K cows such that the minimum distance
//    between any two of them is the maximum possible.
// **** minimum distance between two cows should be maximum
// max(arr(min(distance between cows)))

bool canWePlace(int* arr, int size, int dist, int cows)
{
    int count = 1;
    int last = arr[0];  // last cow placed here --> first cow always place at 0th posn
    for(int i=1; i<size-1; i++)
    {
        cout<< arr[i]<<"-"<<last<<" > "<< dist <<" count-"<<count<< endl;
        if(arr[i] - last >= dist)
        {
            count++;
            last = arr[i];
            
            if(count >= cows)
            {
                return true;
            }
        }
        else{
            continue;
        }
    }

    return false;
}

int AggressiveCows(int* arr, int size, int k)
{
    sort(arr, arr+size);
    // possible stalls will be between max-min
    int min = arr[0];
    int max = arr[size-1];

    for(long long i=1; i<=max; ++i)
    {
        if(!canWePlace(arr, size, i, k ))
        {
            return i-1;
        }
    }
    return min;
}

int AggressiveCowsBS(int* arr, int size, int k)
{
    sort(arr, arr+size);
    int min = arr[0];
    int max = arr[size-1];
    int mid = 0;

    while(min <= max)
    {
        mid = (min+max)/2;
        if(canWePlace(arr, size, mid, k))
        {
            // if can place at mid position than possibly max is greater than mid
            min = mid+1;
        }
        else{
            // if cannot place at mid then ans will be less than mid
            max = mid-1;
        }
    }

    return max; // we have to return max(min(distance possible))
}

int main()
{
    int arr[5] = {10, 1, 2, 7, 5};
    // int arr[5] = {1, 2, 4, 8, 9};
    int k = 3;
    cout << "No of aggressiv cows can be placed AggressiveCows(arr, 5, k) -> "<<
    AggressiveCows(arr, 5, k)<<endl;
    cout << "No of aggressiv cows can be placed AggressiveCowsBS(arr, 5, k) -> "<<
    AggressiveCowsBS(arr, 5, k)<<endl;
}