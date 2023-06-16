#include <iostream>
using namespace std;

void print2DArray(int arr[][4], int rows, int cols)
{
    cout << "2D array printing " << rows*cols << " elements--> " ;
    for(int i=0; i<rows; i++)
    {
        for(int j=0; j<cols; j++)
        {
            cout  << arr[i][j] << " ";
        }
        cout << endl;
    }
}

void input2DArray(int arr[][4], int rows, int cols)
{
    cout << "Enter total " << rows*cols << " elements--> " ;
    for(int i=0; i<rows; i++)
    {
        for(int j=0; j<cols; j++)
        {
            cin >> arr[i][j];
        }
    }
}

int main()
{
    int arr2[3][4] = {0};
    input2DArray(arr2, 3, 4);
    print2DArray(arr2, 3, 4);

}