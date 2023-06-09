#include <bits/stdc++.h>
using namespace std;

int SelectionSort(int arr[], int size){
    for (int i = 0; i < size-1; i++){
        for (int j = i; j < size; j++){
            if (arr[j] < arr[i])
            {
                int temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            } 
        }      
    }
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}

int BubbeSort(int arr[], int size){
    for (int i = 1; i < size; i++)  // this loop runs for an whole iteration
    {
        for (int j = 0; j < size-i; j++)  // this loop is inner iterations which runs for n-1 times
        {
            if (arr[j] > arr[j+1])
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1]= temp;
            }           
        }       
    }
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    
    return 0;
}

void InsertionSort(int arr[], int size){
    for (int i = 1; i < size; i++)
    { 
        int current = arr[i];
        int previous = i-1;
        while (arr[previous]>current && previous>= 0 )  // this loop will compare each new insertes element with previous elems
        {                       // until previous  is greater than current it moves previous to next position
            arr[previous+1] = arr[previous];
            previous--;         // when array elem is moved, var previous returns to its previous posn
        }
        arr[previous+1] = current; //inside loop we down the previous, so 
                                    // after while loop we regain previous+1 = current
    }
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
}


int main(){
    int size;
    int arr[size];
    cout << "Enter Size: ";
    cin >> size;
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }

    cout << "Selection Sort: ";
    SelectionSort(arr, size);
    cout << endl << "Bubble Sort  : ";
    BubbeSort(arr, size);
    cout << endl << "Insertion Sort: ";
     InsertionSort(arr, size);

}