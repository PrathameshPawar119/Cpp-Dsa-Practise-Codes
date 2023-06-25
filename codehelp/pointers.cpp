#include <iostream>
using namespace std;

int main()
{
    int arr[3] = {22, 33, 44};
    cout << "arr addr--> "<< &arr[0]<< endl;
    int *ptr1 = arr;
    ptr1++;
    cout <<"ptr1++ -> "<< ptr1 <<endl;
    cout << "*ptr1 -->"<< *ptr1 << endl;
    cout <<"*arr--> "<< *arr <<endl;
    cout <<"*(arr+1) --> "<< *(arr +1) << endl;
    cout << "chalaki --> "<< 2[arr]<<endl; // reversed chalaki brrooo

    int num = 5;  // 4byte
    int *a = &num;  // 8byte

    cout <<endl<< "before " << num << endl;
    (*a)++;  // *changes value by reference
    // a++;     // changes address
    // a = a+1;  // changes address
    // *a = *a + 1; // *changes value by reference
    cout<<"after "<< num <<endl;


    int temp[10];
    cout <<"sizeof(temp) -> "<< sizeof(temp)<<endl;
    int *ptr2 = &temp[0];
    cout <<"sizeof(ptr2) -> "<< sizeof(ptr2) << endl;
    cout <<"sizeof(*ptr2) -> "<< sizeof(*ptr2) << endl;

}