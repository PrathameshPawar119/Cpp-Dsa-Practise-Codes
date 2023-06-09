#include <iostream>
#include "../default_funcs.cpp"
using namespace std;

// Reverse an given array or string
void ArrRev(int arr[], int size)
{
    int start = 0;
    int end = size-1;

    while(start < end)
    {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp; 
        start++;
        end--;
    }
}

int main()
{
    int arr[10] = {1,2,3,4,5,6,7,8};
    ArrRev(arr, 8);
    printArray(arr, 8);

}