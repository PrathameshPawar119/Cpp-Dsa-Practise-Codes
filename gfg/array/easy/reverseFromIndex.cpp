#include <iostream>
#include "../default_funcs.cpp"
using namespace std;

void reverseArrayFromIndex(int arr[], int size, int index)
{
    int s = index, e = size-1;
    while(s < e)
    {
        swap(arr[s], arr[e]);
        s++;
        e--;
    }
}

int main()
{
    int arr[6] = {1,2, 3, 4, 5, 6};
    reverseArrayFromIndex(arr, 6, 3);
    printArray(arr, 6);
}