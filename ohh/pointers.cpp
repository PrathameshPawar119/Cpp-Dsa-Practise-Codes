#include <bits/stdc++.h>
using namespace std;

void SwapCBR(int a, int b){ // do not works
    // By using call by ref
    int temp = a;
    a = b;
    b = temp;
}

void SwapCBV(int *a, int *b){ // works
    // By usng Call By val
        int temp = *a;
        *a = *b;
        *b = temp;
}

int main(){

    int arr[] = {2,3,4,5};
    cout << *arr << endl; // --> 2 (first element)

    int *ptr = arr;
    cout << *ptr <<", " << ptr << endl;

    // Print array using pointers
    for (int i = 0; i < 4; i++)
    {
        cout << *ptr << " ";  // printing element *ptr present at position ptr
        ptr++; // moving address to next position
    }

    // swap two vaiables 
    int a = 2, b = 4;

    cout<< "\n By Call By value : ";
    SwapCBR(a,b);
    cout << a << " "<< b<<endl;

    cout << " By Call By ref : ";
    SwapCBV(&a, &b);
    cout << a << " " << b << endl;
} 


/* 
For temporary work we can send values to function so original varibles don't affect
But to modify original varibles we have to use call by reference by using pointers.
*/




/*
Difference Between i+1 and i++
i+1 = move to next location
i++ = move to next iterator

therefore, in caes of array or vector they both are same because of contigous nature
but In case of maps or sets which are not contigous in nature so i+1 may be invalid in this case.
*/