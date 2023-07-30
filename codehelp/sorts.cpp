#include <iostream>
using namespace std;

void printArr(int* arr,  int size)
{
    cout << endl << "printArray-->"<<endl;
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void SelectionSort(int arr[], int size){
    for (int i = 0; i < size-1; i++){
        int min_pos = 0, min = arr[0];
        for (int j = i; j < size; j++){
            if (arr[j] < arr[i])
            {
               min = arr[j];
               min_pos = j;
            } 
        }  
        swap(arr[i], arr[min_pos]);    
    }
    printArr(arr, size);
}


void BubbeSort(int arr[], int size){
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
    printArr(arr, size);
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
    printArr(arr, size);
}

// engine of mergeSort function
void merge(int* arr, int s , int e, int& conversions)
{
    int mid = (s+e)/2;
    int len1 = mid-s+1;
    int len2 = e-mid;

    int* left = new int [len1];
    int* right = new int [len2];

    int mainArrayIndex = s;
    for(int i=0; i<len1; i++)
    {
        left[i] = arr[mainArrayIndex++];
    }
    mainArrayIndex = mid+1;
    for(int i=0; i<len2; i++)
    {
        right[i] = arr[mainArrayIndex++];
    }


    // now merge 2 sorted arrays
    int index1 = 0;
    int index2 = 0;
    mainArrayIndex = s;

    while(index1 < len1 && index2 < len2)
    {
        if(left[index1] <= right[index2])
        {
            arr[mainArrayIndex++] = left[index1++];
        }
        else{
            arr[mainArrayIndex++] = right[index2++];

            // len1-index1 gives total number of elements from left greater current element of right
            // as total left elements greater than current right represents count inversions required
            conversions += len1-index1;
        }
    }

    while(index1 < len1)
    {
        arr[mainArrayIndex++] = left[index1++];
    }
    while(index2 < len2)
    {
        arr[mainArrayIndex++] = right[index2++];
    }


    delete [] left;
    delete [] right;

}
// merge sort (divide and conquer)
void mergeSort(int* arr, int s, int e, int& conversions)
{
    // base condition
    if( s >= e) return; // single element is already sorted so return;

    int mid = (s+e)/2;

    //merge left part
    mergeSort(arr, s, mid, conversions);

    // merge right part
    mergeSort(arr, mid+1, e, conversions);

    merge(arr, s, e, conversions);

}

int partition(int* arr, int l, int h)
{
    int pivot = arr[l];
    int count = 0;
    for(int i=l+1; i < h; i++)
    {
        if(arr[i] <= pivot) count++;
    }

    int pivotIndex = l+count;
    swap( arr[pivotIndex], arr[l]);
    
    int i=l, j = h;
    while(arr[i] < pivotIndex && arr[j] > pivotIndex)
    {
        while(arr[i] <= pivot)
        {
            i++;
        }
        while(arr[j] > pivot)
        {
            j--;
        }

        //  when above both loops stops workinh
        if(arr[i] < pivotIndex && arr[j] > pivotIndex)
        {
            swap(arr[i++], arr[j--]);
        }
    }
    
    return pivotIndex;

}

void quickSort(int* arr, int l, int h)
{
    if(l >= h) return;

    int pivot = partition(arr, l, h);

    // left part of partition
    quickSort(arr, l, pivot-1);

    // right part of partition
    quickSort(arr, pivot+1, h);
}

int main(){
    int arr[8] = {1, 2, 3, 4, 5, 6, 8, 7};
    // int arr[4] = {1, 5, 12, 3};
    int size = 8;

    // cout << "Selection Sort: ";
    // SelectionSort(arr, size);
    // cout << endl << "Bubble Sort  : ";
    // BubbeSort(arr, size);
    // cout << endl << "Insertion Sort: ";
    // InsertionSort(arr, size);

    int conversions = 0;
    cout << "merge sort  " ;
    mergeSort(arr, 0, size-1, conversions);
    printArr(arr, size);
    cout << "inversion_count -> "<<conversions<< endl;

    cout << "QuickSort  ";
    quickSort(arr, 0 , size);
    printArr(arr, size);


}