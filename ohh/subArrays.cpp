#include <bits/stdc++.h>
using namespace std;

void AllPossibleSubarr(int arr[], int size){
    cout << "Possible SubArrays: ";
    for (int i = 0; i < size; i++)
    {
        for (int j = i; j < size; j++)
        {
            for (int k = i; k <= j; k++)
            {
                cout<< arr[k]<< " ";
            }
            cout << "-";
        }
    }
}


// Subarray with maximum sum
void MaxSumSubarr(int arr[], int size){
    cout << "Maximum Sum of subArr: ";
    int maxSum = INT_MIN;
    for (int i = 0; i < size; i++)
    {
        int sum = 0;
        for (int j = i; j < size; j++)
        {
            sum += arr[j];
           if (sum < 0)
            {
                break;
            }
            maxSum = max(maxSum, sum);
        }
    }
    cout << maxSum;
}

int minFromArr(int arr[], int size){
    int mini = INT_MAX;
    for (int i = 0; i < size; i++)
    {
        for (int j = i; j < size; j++)
        {
            mini = min(mini, arr[j]);
        }
        
    }
    return mini;
}

// Max Sum of circular array
// max sum of circular array = total sum of array - sum of non contributing elementd
int maxSumOfSubseqFromCircularArr(int arr[], int size){
    int mini = minFromArr(arr, size);
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += arr[i];
    }
    int Max_From_CArray = sum-mini;
    return Max_From_CArray; 
}

// Pair sum problem - check there exists two elems whose sum = k
bool pairSum(int arr[], int size, int key){
    for (int i = 0; i < size; i++)
    {
        for (int j = i; j < size; j++)
        {
            if (arr[j]+arr[j+1] == key)
            {
                cout << j <<"-"<< j+1 << " ";
                return true;
            }   
        }   
    }
    return false;
}

// Pair sum problem using only one loop
bool pairSumPro(int arr[], int size, int key){
    int low = 0;
    int high = size-1;
    while (low < high)
    {
        if (arr[low]+arr[high] == key)
        {
            cout << low<<"-"<< high <<endl;
            return true;
        }
        else if(arr[low]+arr[high] > key){
            high--;
        }else{
            low++;
        }
    }
    return false;
}


int main(){
    int size;
    cout << "Enter Size: ";
    cin >> size;

    int arr[size];
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }

    // AllPossibleSubarr(arr, size);
    // MaxSumSubarr(arr, size);
    // cout<< minFromArr(arr, size);
    // cout << maxSumOfSubarrFromCircularArr(arr, size);
    //  cout << pairSum(arr, size, size); //here size == key
     cout << pairSumPro(arr, size, size); //here size == key
}