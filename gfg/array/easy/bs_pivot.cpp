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

int main()
{
    // int arr[5] = {6, 7, 9, 11, 2};
    int arr[5]  = {4, 6, 8, 1, 2};
    int size = sizeof(arr)/sizeof(arr[0]);
    int pivot_position = findPivotPosition(arr, size);

    cout << pivot_position << endl;
}