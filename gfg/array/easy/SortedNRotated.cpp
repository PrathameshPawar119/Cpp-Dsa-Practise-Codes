#include <iostream>
using namespace std;
// We have to check that given array is sorted  and rotated


bool CheckIfSortedNRotated(int arr[], int size)
{
    // Get Pivot
    int pivot = 0;
    for(int i=0; i< size; i++)
    {
        if(arr[i+1] < arr[i])
        {
            pivot = i;
            break;
        }
    }
    // reverse rotate again That array
    int newArr[size];
    for(int i=0; i< size; i++)
    {
        newArr[(i+(size-pivot-1))%size] = arr[i];
    }

    // check if sorted
    for(int i=0; i<size-1; i++)
    {
        if(newArr[i+1] < newArr[i])
        {
            return false;
        }
    }

    return true;

}

// Second Approach 
// wrong in case of unrotated sorted array
bool CheckIfSortedNRotated2(int arr[], int size)
{
    // Get Pivot
    int pivot = 0;
    for(int i=0; i< size; i++)
    {
        if(arr[i+1] < arr[i])
        {
            pivot = i;
            break;
        }
    }

    for(int i=0; i<size; i++)
    {
        int temp = (i+pivot)%size;
        if(arr[temp] > arr[temp+1] && temp != pivot){
            return false;
        }
    }

    return true;
}

// Best Solution
// Third Approach // shortcut by lb
bool CheckIfSortedNRotated3(int arr[], int size)
{
    int counts = 0;
    for(int i=1; i<size; i++)
    {
        if(arr[i+1] < arr[i])
        {
            counts++;
        }
    }
    if(arr[size-1] > arr[0])
    {
        counts++;
    }
    return counts<=1;
    
}

int main()
{
    // int arr[5] = {1, 2, 3, 4, 5};
    // int arr[5] = {4,5, 1, 2, 3};
    // int arr[5] = {4,1, 1, 2, 3};
    int arr[3] = {1, 1, 1};
    cout <<"Is rotated & sorted 1? --> "<< CheckIfSortedNRotated(arr, 5) << endl;
    cout <<"Is rotated & sorted 2? --> "<< CheckIfSortedNRotated2(arr, 5) << endl;
    cout <<"Is rotated & sorted 3? --> "<< CheckIfSortedNRotated3(arr, 5) << endl;
}