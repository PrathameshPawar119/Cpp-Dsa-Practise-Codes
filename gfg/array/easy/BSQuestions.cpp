#include <iostream>
using namespace std;

void FirstAndLast(int* arr, int size, int target)
{
    cout <<endl<< "FirstAndLast --> " ;
    int s = 0;
    int e = size-1;
    int ans = -1;
    while(s<=e)
    {
        //First Half
        int mid = (s+e)/2;
        if(arr[mid] == target)
        {
            ans = mid;
            e = mid-1;
        }
        else if(arr[mid] < target)
        {
            s = mid+1;
        }
        else{
            e = mid-1;
        }
    }
    cout << "First- " << ans ;

    s = 0;
    e = size-1;
    while(s<=e)
    {
        // second half
        int mid = (s+e)/2;
        if(arr[mid] == target)
        {
            ans = mid;
            s = mid+1;
        }
        else if(arr[mid] < target)
        {
            s = mid+1;
        }
        else{
            e = mid-1;
        }
    }
    cout << " Last- " << ans;
    cout << endl;
}

int PeakInMountain(int* arr, int size)
{
    int s=0;
    int e = size-1;
    while(s<=e)
    {
        int mid = (s+e)/2;
        if(arr[mid] < arr[mid+1])
        {
            s = mid+1;
        }
        else{
            e = mid-1;
        }
    }
    return s;

}

int AggressiveCows()


int main()
{
    int arr[9] = {3, 4, 4, 4, 6, 9, 11, 11, 16};
    FirstAndLast(arr, 9, 4);

    int arr2[5] = {1, 2, 4 ,1};
    cout << "PeakInMountain --> "<<PeakInMountain(arr2, 5);

}