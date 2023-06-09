#include <iostream>
#include "../gfg/array/default_funcs.cpp"
using namespace std;

// Q- given array of page numbers of each book
// ex- {10, 20, 30, 40}
// allocate all books in n students with minimum difference in pages
// contagous distribusion compulsory

int distributeBooks(int arr[], int size, int m)
{
    int min = INT_MAX;
    sort(arr, arr + size);
    if(m > size)
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

int main()
{
    int arr[6] = {10, 30, 90, 100, 120, 200};
    int size = sizeof(arr)/sizeof(arr[0]);

    cout << "min diff--> "<< distributeBooks(arr, size, 2);

    return 0;
}