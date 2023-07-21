#include <iostream>
#include <algorithm>
#include "../default_funcs.cpp"
using namespace std;

void MergeSortedArays2(int arr1[], int n1, int arr2[], int n2)
{
    int left = n1-1;
    int right = 0;
    
    while(left >= 0 && right < n2)
    {
        if(arr1[left] > arr2[right])
        {
            int temp = arr2[right];
            arr2[right] = arr1[left];
            arr1[left] = temp;

            left--; right++;
        }
        else{
            break;
        }
    }

    sort(arr1, arr1+n1);
    sort(arr2, arr2+n2);

}

int main()
{
    int arr1[4] = {1, 3, 5, 7};
    int arr2[3] = {2, 6, 11};

    MergeSortedArays2(arr1, 4, arr2, 3);
    //this is same like merging two sorted arrays just trick is
    //here we cannot create new array put sorted nums in arr1

    printArray(arr1, 4);
    printArray(arr2, 3);

}