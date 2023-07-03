#include <iostream>
using namespace std;

void input2DArr(int** arr, int r, int c)
{
    cout << "Enter " << r*c << " elems of arr -> ";
    for(int i=0; i<r; i++)
    {
        for(int j=0; j<c; j++)
        {
            cin>> arr[i][j];
        }
    }
}
void print2DArr(int** arr, int r, int c)
{
    cout << r*c << " elems of arr -> " << endl;
    for(int i=0; i<r; i++)
    {
        for(int j=0; j<c; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}


void incr(int a)
{
    //  pass by value
    a = a+1;
}

void incr2(int &a)
{
    // pass by ref
    a = a+1;
}

int *fun(int n)
{
    int *ptr = &n;
    return ptr;
}


int main()
{
    int a = 5;
    int &b = a;

    cout << "a -> "<< a <<endl;
    incr(a);
    cout << "a -> "<< a <<endl;
    incr2(a);
    cout << "a -> "<< a <<endl;

    cout << "fun(a)-> "<< fun(a) <<endl;

    int r, c;
    cout << "enter num of rows & col for dynamic 2d arr -> ";
    cin >> r >> c;

    // int *arr = new int [r]; // for 1d array
    // for 2darr ->
    int** arr = new int* [r];
    for(int i=0; i< r; i++)
    {
        arr[i] = new int [c];
    }

    // verify
    input2DArr(arr, r, c);
    print2DArr(arr, r, c);
    
    // after allocation, De-allocate the memory
    for(int i=0; i<r; i++)
    {
        delete[] arr[i];
    }
    delete[] arr;

    return 0;

}