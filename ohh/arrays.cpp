#include <bits/stdc++.h>
using namespace std;

int MinMax(int arr[], int size){
    int max = arr[0];
    int min = arr[0];
    for (int i = 1; i < size; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
        if (arr[i] < min)
        {
            min = arr[i];
        }
    }
    cout << "Greater: "<<max<<", Smaller: "<<min;
    return 0;
}

int LinearSearchArr(int arr[], int size, int key){
    cout << "Positions : ";
    for (int i = 0; i < size; i++)
    {
        if (key == arr[i])
        {
            cout << i << " ";
        }
    }
    return -1;
}

int BinarySearchArr(int arr[], int size, int key){
    int s = 0;
    int e = size-1;
    cout<< "Positions : ";
    while (s <= e)
    {
        int mid = (s+e)/2;
        if (arr[mid] == key)
        {
            return mid;
            // s = mid + 1;  //try this 
        }
        else if (arr[mid] < key)
        {
            s = mid+1;
        }
        else
        {
            e = mid-1;
        }
    }  
        return -1;
}

// Finding maximum from array using max()
int MaxPattern(int arr[], int size){
    int ans = INT_MIN;

    for (int i = 0; i < size; i++)
    {
       int temp = max(ans, arr[i]);
       if (temp == arr[i])
       {
            ans = arr[i];
       }  
    }
    return ans;
}

// Sum of All possible subArrays
void SumOfSubArr(int arr[], int size){
    cout << "Possible sums of subarrays: ";
    for (int i = 0; i < size; i++)
    {   
        int sum = 0;
        for (int j = i; j < size; j++)
        {
            sum = sum + arr[j];
            cout << sum << " ";
        }
    }
}


// Sum of Largest Arithmetic subArray  (arithmetic - diff between adjacent two is constant)
void SumOfLargestArithSubarr(int arr[], int size){
    cout << endl << "SumOfLargestArithSubarr: " ;
    for (int i = 0; i < size; i++)
    {
        int ans = 0;
        int pd = arr[1]-arr[0]; // previous diff
        int currnt = 2;
        for (int j = 2; j <= size; j++)
        {
            if (pd == arr[j]-arr[j-1])
            {
                currnt++;
            }
            else
            {
                pd = arr[j]-arr[j-1];
                currnt = 2;
            }
             ans = max(ans, currnt);
        }
        cout << ans << " ";
    }
}


// Record Breaking Days = biggrst than all pre elems and only one next
void RecordBreakingDays(int arr[], int size){
    cout << " Record Breaking Days : ";
    int maxi = INT_MIN;
    int days = 0;
    if (size == 1)
    {
        cout << 1 <<" ";
    }
    else{
        for (int i = 0; i < size; i++)
        {
            if ((arr[i] > maxi) && (arr[i] > arr[i+1]))
            { 
                days++;
            }
            maxi = max(arr[i], maxi);
        }
        cout <<"-"<< days <<"-";
    } 
}

// First Repeating Elem
void FirstRepeatingElem(int arr[], int size){
    int n = 1e5;
    int temp[n];
    int elem;
    for (int i = 0; i < n; i++)
    {
        temp[i] = -1;
    }

    int minTemp = INT_MAX;
    for (int i = 1; i < size; i++)
    {
        if (temp[arr[i]] != -1)
        {
            minTemp = min(minTemp, temp[arr[i]]);
            elem = arr[i];
        }
        else{
            temp[arr[i]] = i;
        }
    }
    if (minTemp == INT_MAX)
    {
        cout <<endl<< "MiniTemp = -1 " ;
    }
    else{
    cout <<endl<< "Index: "<< minTemp << " & Elem: " << elem;
    }
    
}

// Sum of all possible subarrays having given sum S
void SumOfSubarryFor(int arr[], int size, int key){
    cout << "Indexes of possible subarrays for key "<< key<<": ";
    int total = 0;
    for (int i = 0; i < size; i++)
    {
        int sum = 0;
        for (int j = i; j < size; j++)
        {
            sum = sum +arr[j];
            if (sum == key)
            {
                cout << i <<"-"<<j<< " ";
                total++;
            }  
            if (sum>key)
            {
                break;
            }
        } 
    }
    cout << "\nTotal possible subarrs: "<<total;
}

// To provide Smallest positive integar
int SmallestPositive(int arr[], int size){
    int mini = INT_MAX;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] < mini && arr[i]>0)
        {
            mini  = arr[i];
        }
        
    }
    cout << "minimum positive int: "<< mini;
    return 0;
}


int main(){
    // int arr[] = {1,2,3,4,5};
    // int size = sizeof(arr)/sizeof(arr[0]);
    // cout << MinMax(arr, size) << endl;

    int n;
    cout << "Enter size n: ";
    cin >> n;

    int arr2[n];
     for (int i = 0; i < n; i++)
    {
        cin >> arr2[i];
    }
    
    int key;
    cout << "Enter key: ";
    cin >> key;

    // cout << LinearSearchArr(arr2, n, key) << endl;
    // cout << BinarySearchArr(arr2, n, key) << endl;  // Only works for sorted arrays
    // cout << MaxPattern(arr2, n) << endl;
    // SumOfSubArr(arr2, n);
    // SumOfLargestArithSubarr(arr2, n);
    // RecordBreakingDays(arr2, n);
    // FirstRepeatingElem(arr2, n);
    // SumOfSubarryFor(arr2, n, key);
    SmallestPositive(arr2, n);
}