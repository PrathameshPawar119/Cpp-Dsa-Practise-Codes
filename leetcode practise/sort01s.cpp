#include<iostream>
using namespace std;

void printArr(int arr[], int size){
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
}

void oneSort(int arr[], int size){
    int start = 0;
    int end = size-1;
// 2 Pointer Method
    while (start <= end)
    {
        if (arr[start] == 1 && arr[end]==0)
        {
            swap(arr[start], arr[end]);
            start++; end--;
        }
    }
    printArr(arr, size);
    
}

int main(){

    int arr[14] = {0,1,1,0,0,1,0,0,1,0,1,0,0,1};
    int size = 14;

    // Bubble sort
    for (int i = 0; i < size; i++)
    {
        for (int j = i; j < size; j++)
        {
            if (arr[i]==1 && arr[j]==0)
            {
                swap(arr[i], arr[j]);
            }
            
        }
        
    }
    printArr(arr, 14);

    // oneSort(arr, size);
    

}
