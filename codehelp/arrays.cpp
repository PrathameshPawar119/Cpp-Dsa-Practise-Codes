#include<iostream>
using namespace std;

void printArray(int arr[], int size)
{
    cout << " Array Start - " << endl; 
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] <<" ";
    }
    cout <<endl<< " - Array End ";
}

void printCharArray(char arr[], int size){
    cout << " CharArray Start - " << endl;
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout <<endl<< " - CharArrayEnd ";
    
}

void arrMinMax(int arr[], int size){
    int max = INT_MIN ;
    int min = INT_MAX;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
        if(arr[i] < min){
            min = arr[i];
        }  
    }
    cout<<endl<< "Min = " << min <<" Max = "<<max<<endl;
}

void PrintNupdateArray(int arr[], int size){
    arr[size-1] = 999;
    cout << " Array Start - " << endl;
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl<< " - Array End ";
}

int main(){
    int arr[10];
    // How to fill an array with same value other than 0
    fill_n(arr, 10, 1);
    
    int arr2[10] = {4,1,3,1};
    cout << sizeof(arr2)/sizeof(int) << endl;   // prints 10, should be 3
    printArray(arr2, 10);

    // char a = 'a';
    // char arr3[5] = {a, a+1, a+2, a+3, a+4};
    // printCharArray(arr3, 5);

    arrMinMax(arr2, 4);
    
    int arr3[5] = {1,2,3,4,2};
    PrintNupdateArray(arr3, 5);

    printArray(arr3, 5);


}