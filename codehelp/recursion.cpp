#include <iostream>
#include <algorithm>
using namespace std;

void PrintArr(int* arr, int size)
{
    cout << endl;
    for(int i=0; i<size; i++){
        cout<<arr[i] << " ";
    }
        cout << endl;
}

int powerOfTwo(int n)
{
    if(n == 0)
    {
        return 1;
    }

    return 2 * powerOfTwo(n-1);
} 

int print( int e, int s = 0)
{
    if(e == s)
    {
        return s;
    }

    cout << e << " ";
    return print(e-1, s);
}

int facto(int n)
{
    if(n == 1 || n == 0)
    {
        return 1;
    }

    return n * facto(n-1);
}

int fibonacci(int n)
{
    if(n == 0 || n == 1)
    {
        return n;
    }

    return fibonacci(n-1)+fibonacci(n-2);
}

bool isArrSorted(int* arr, int size, int id = 0)
{
    if(id == size-1)
    {
        return true;
    }

    return arr[id] <= arr[id+1] && isArrSorted(arr, size, id+1);
}

// check sorted without third variable
bool isArrSorted2(int* arr, int size)
{
    if(size <= 0)
        return true;
    if(arr[0] > arr[1])
    {
        return false;
    }
    else
    {
        bool ans = isArrSorted2(arr+1, size-1);
        return ans;
    }
    return false;
}

int arrSum(int* arr, int size)
{
    if(size <= 0)
    {
        return 0;
    }

    int ans = arr[0] + arrSum(arr+1, size-1);
    return ans;

}

int RecusresiveBS(int *arr, int s, int e, int k)
{
    // base case - element not found
    if(s>e)
    {
        return -1;
    }

    // base case - element found
    int mid = (s+e)/2;
    if(arr[mid] == k)
    {
        return mid;
    }

    if(arr[mid] < k)
    {
        return RecusresiveBS(arr, mid+1, e, k);
    }
    else{
        return RecusresiveBS(arr, s, mid-1, k);
    }
}

int main()
{
    int n = 6;
    int *arr = new int [n];
    for(int i = 0; i<n-1; i++)
    {
        arr[i] = i;
    }
    arr[n-1] = 2;
    PrintArr(arr, n);

    cout <<"powerOfTwo(5)--> "<<powerOfTwo(n)<<endl;
    cout << "print(5, 2)--> "<< print(n, 2) <<endl;
    cout << "facto(5)--> "<< facto(n) << endl;
    cout << "Fibonacci(5)--> " << fibonacci(n) << endl;
    cout << "isArrSorted(arr, n) --> " << isArrSorted(arr, n) << endl;
    cout << "isArrSorted2(arr, n)-->" <<isArrSorted2(arr, n) << endl;
    cout << "arrSum(arr, n) -->" << arrSum(arr, n) << endl;
    cout << "RecusresiveBS(arr, 0, n-1,4) --> " << RecusresiveBS(arr, 0, n-1, 4)<<endl;
 

    delete [] arr;

}