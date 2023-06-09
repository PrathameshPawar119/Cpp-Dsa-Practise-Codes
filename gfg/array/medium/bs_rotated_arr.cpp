#include <iostream>
using namespace std;

int findPivotPosition(int arr[], int size)
{
    int s = 0;
    int e = size-1;
    while(s < e)
    {
        int mid = (s+e)/2;
        if(arr[mid] > arr[0])
        {
            s = mid+1;
        }
        else{
            e = mid-1;
        }
    }
    return s;
}

int binarySearch(int arr[], int s, int e, int target)
{
    while(s < e)
    {
        int mid = (s+e)/2;
        if(arr[mid] == target)
        {
            return mid;
        }
        if(arr[mid] < target)
        {
            s = mid+1;
        }
        else{
            e = mid-1;
        }
    }
    return -1;
}

int main()
{
    int arr[1] = {1};
    int target = 2;
    int size = sizeof(arr)/sizeof(arr[0]);

    int pivot = findPivotPosition(arr, size);

    if(arr[pivot] < target && target <= arr[size-1])
    {
        // BS in Second array or line
      cout <<  binarySearch(arr, pivot, size-1 , target);
    } 
    else{
        // BS in First array or line
        cout << binarySearch(arr, 0, pivot, target);
    }
}