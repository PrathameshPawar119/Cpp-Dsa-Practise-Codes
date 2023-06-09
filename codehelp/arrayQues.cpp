#include<iostream>
using namespace std;

void printArray(int arr[], int size)
{
    cout << " Array Start - " << endl;
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout <<endl<< " - Array End ";
}

void ArrLinearSearch(int arr[], int size, int target){
    int found = false;
    cout<<endl;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == target)
        {
            cout << ", Element {" << target << "} found at arr "<<i;
            found = true;
        }
    }
    if (!found)
    {
        cout << " Element Not found ";
    }
    cout << endl;
}

int ArrBinarySearch(int arr[], int size, int target){
    // useful for only SORTED array  
    int start = 0;
    int end = size-1;
    int res = -1;
    while (start <= end)
    {
        int mid = (start+end)/2;
        if(arr[mid] == target){
            return mid;
            break;
        }
        if (arr[mid] < target)
        { 
            start = mid+1;
        }
        else{
            end = mid-1;
        }
    }
    return res;
}

void quickReverseArray(int arr[], int size){
    int start = 0;
    int end = size-1;
    for (int i = 0; i < size/2; i++)
    {
        if (start == end){
            break;
        }
        else{
            int temp = arr[end];
            arr[end] = arr[start];
            arr[start] = temp;
            start++;
            end--;
        }
    }
}

void printReverseArray(int arr[], int size){
    // /make a reveresed copy of arr
    int rev[size] = {0};
    for (int i = 0; i < size; i++)
    {
        rev[i] = arr[size-1-i];
    }
    printArray(rev, 8);
}

void reverseArray(int arr[], int size){
    // reverse the arr
    int rev[size] = {0};
    for (int i = 0; i < size; i++)
    {
        rev[i] = arr[size - 1 - i];
    }
    for (int i = 0; i < size; i++)
    {
        arr[i] = rev[i];
    }
}

void swapAlternateFromArr(int arr[], int size){
    for (int i = 0; i < size; i++)
    {
        if (i != size-1)
        {
           swap(arr[i], arr[i+1]); 
        }
        i++;
    }   
}

void FindUniqueElements(int arr[], int size){
    // My Approach
    // 2, 2, 3, 5, 8, 8, 5, 9
    cout << "\n Unique Elements = ";
    int seq = 0;
    for (int i = 0; i < size; i++)
    {
        int j = 0;
        seq = 0;
        while (j < size)
        {
            if (arr[i] == arr[j])
            { // found once ok
                seq++;
            }
            j++;
            if (seq == 2)
            { //found again delete
                break;
            }
        }
        
        if (seq==1)
        { 
            cout << arr[i] << ", ";
        }
    }
}

void findUniqueElements2(int arr[], int size){
    int ans = 0;
    for (int i = 0; i < size; i++)
    {
        ans = ans^arr[i];
    }
    cout << ans << " ";
}
//  0101^0101  --> 0000
int findDuplicateElements(int arr[], int size){
    int ans = 0;
    for (int i = 0; i < size; i++)
    {
        ans = ans^arr[i];
    }
    // now ans is unique elem
    for (int i = 0; i < size; i++)
    {
        ans = ans^i;
    }
    return ans;
}

void MergeSortedArays(int arr1[], int n, int arr2[], int m, int arr3[])
{
    int i = 0, j = 0;
    int itr = 0;
    while(i < n && j < m)
    {
        if(arr1[i] < arr2[j])
        {
            arr3[itr] = arr1[i];
            i++;
        }
        else{
            arr3[itr] = arr2[j];
            j++;
        }
        itr++;
    }

    //copy remaining elems of arr1
    while(i<n)
    {
        arr3[itr] = arr1[i];
        itr++; i++;
    }
    //copy remaining elems of arr2
    while(j<n)
    {
        arr3[itr] = arr2[j];
        j++; itr++;
    }
}


int main(){
    int arr1[8] = {1,2,4,2,5,3,8,5};
    ArrLinearSearch(arr1, 8, 2);

    // sorted aray
    int arr2[8] = { -1, 0, 3, 5, 9, 12 };
    cout <<" Element Position " << ArrBinarySearch(arr2, 6, 9)<<endl;

    printReverseArray(arr2, 8); // make reverse copy of array
    // reverseArray(arr2, 8); // reverse the arr
    quickReverseArray(arr2, 8); //reverse the arr

    printArray(arr2, 8);

    int arr3[8] = {2,3,4,5,7,8,9};
    swapAlternateFromArr(arr3, 7);
    printArray(arr3, 7);

    int arr4[8] = {2,2,3,5,8,8,5,9};
    FindUniqueElements(arr4, 8);
    findUniqueElements2(arr4, 8);

    printArray(arr4, 8);
    cout <<endl<< findDuplicateElements(arr4, 8);


    cout << endl << "MergeSortedArrYs "<<endl;
    int x[4] = {1, 3, 5, 7};
    int y[3] = {2, 4, 6};
    int z[7] = {};
    MergeSortedArays(x, 4, y, 3, z);
    printArray(z, 7);
}