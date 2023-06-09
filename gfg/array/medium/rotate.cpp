#include <iostream>
#include "../default_funcs.cpp"
using namespace std;

void rotate(int arr[], int size, int key)
{
    for(int i=0; i <key; i++)
    {
        int temp = arr[0];
        for(int j=0; j<size-1; j++)
        {
            int temp2 = arr[j+1];
            arr[j+1] = temp;
            temp = temp2;
        }
        arr[0] = temp;
    }
}

int main()
{
    int arr[8] = {1, 2, 3, 4, 5, 6, 7, 8};
    int size = sizeof(arr)/sizeof(int);

    printArray(arr, size);
    rotate(arr, size, 3);
    printArray(arr, size);
}