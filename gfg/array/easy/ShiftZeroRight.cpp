#include <iostream>
#include "../default_funcs.cpp"
using namespace std;
// Shift all zeroes present in array to right
// ex->  [1, 0, 2, 3, 0, 0, 5, 0]--> [1, 2, 3, 5, 0, 0, 0, 0]

void shiftZeroestoRIght(int arr[], int size)
{
    // Actually it shifts all NonZeroes to left by swap
    int NonZero = 0;
    for(int i=0; i< size; i++)
    {
        if(arr[i] != 0)
        {
            swap(arr[NonZero], arr[i]);
            NonZero++;
        }
    }
    /// please try paper execeution then u will understand
}

int main()
{
    int arr[8] = {1, 0, 2, 3, 0, 0, 5, 0};
    shiftZeroestoRIght(arr, 8);
    printArray(arr, 8);

}