#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int minSwapstoSort(int arr[], int n)
{
    vector<pair<int, int>> vect(n);
    for(size_t i = 0; i < n; ++i)
    {
        vect[i] = {arr[i], i};
    }
    sort(vect.begin(), vect.end());

    int count = 0;
    for(size_t i = 0; i <n; ++i)
    {
        if(vect[i].second == i)
        {
            continue;
        }
        count++;
        swap(vect[i], vect[vect[i].second]);
    }

    return count;
}


int main()
{
    int arr[5] = {1, 5, 4, 3, 2};
    int minSwaps = minSwapstoSort(arr, 5);
    cout << "minSwaps -> " << minSwaps <<endl;

}