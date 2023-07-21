#include <iostream>
#include <algorithm>
using namespace std;

void print2DArray(int arr[][4], int rows, int cols)
{
    cout <<endl<< "2D array printing " << rows*cols << " elements--> " <<endl;
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

void rowWiseSum(int arr[][4], int rows, int cols)
{
    int max = INT_MIN;
    int  max_row = 0;

    cout <<endl<< "Row wise sum --> ";
    for(int i=0; i<rows; i++)
    {
        int sum = 0; 
        for(int j=0; j<cols; j++)
        {
            sum += arr[i][j];
        }
        cout << sum << " ";
        if(sum > max)
        {
            max = sum;
            max_row = i;
        }
    }
    cout << "Largest row sum-> " << max << " in row "<<max_row;
}

void colWiseSum(int arr[][4], int rows, int cols)
{
    cout <<endl<< "col wise sum --> ";
    for(int i=0; i<cols; i++)
    {
        int sum = 0;
        for(int j=0; j<rows; j++)
        {
            sum += arr[j][i];
        }
        cout << sum << " ";
    }
}

void wavePrint(int arr[][4], int rows, int cols)
{
    cout<<endl<< "Wave Print --> ";
    for(int col =0; col < cols; col++)
    {
        if( col&1)
        {
            //odd index --> bottom to top
            for(int row = rows-1; row>=0; row--)
            {
                cout << arr[row][col] << " ";
            }
        }
        else
        {
            // even index or zero --> top to bottom
            for(int row=0; row<rows;row++)
            {
                cout << arr[row][col] << " ";
            }

        }

    }
}

void spiralPrint(int arr[][4], int rows, int cols)
{
    cout <<endl<< "Spiral print--> "; 

    int count = 0;
    int total = rows*cols;

    // indx inititalization
    int starting_row = 0;
    int starting_col = 0;
    int ending_row = rows-1;
    int ending_col = cols-1;

    while(count < total-1)
    {
        // print start row
        for(int i = starting_row; i<= ending_col; i++)
        {
            cout << arr[starting_row][i] << " ";
            count++;
        }
        starting_row++;

        // print ending col
        for(int i = starting_row; i<= ending_row; i++)
        {
            cout << arr[i][ending_col] << " ";
            count++;
        }
        ending_col--;

        // print ending row
        for(int i = ending_col; i >= starting_col; i--)
        {
            cout << arr[ending_row][i] << " ";
            count++;
        }
        ending_row--;

        // print starting column
        for(int i = ending_row; i >= starting_row;i--)
        {
            cout << arr[i][starting_col] << " ";
            count++;
        }
        starting_col++;
    }
}

 void rotateMatrix(int matrix[][4], int rows, int cols) {

    // this trick works only for nxn matrix 

    // swap diagonals
     for(int i=0; i<rows; i++)
     {
        for(int j = 0; j<= i; j++)
        {
            swap(matrix[i][j], matrix[j][i]);
        }
     }

    //  //reverse rows
     for(int i=0; i<cols/2; i++)
     {
        for(int j=0; j<cols; j++)
        {
            swap(matrix[i][j], matrix[i][cols-i-1]);
        }
     }

}

bool binarySearch2dArr(int arr[][4], int rows, int cols, int target)
{
    int s = 0;
    int e = rows*cols-1;

    while(s <= e)
    {
        // this mid is for lienar version of 2d array
        int mid = (s+e)/2;

        // elem is 2d version or linear->2d
        int elem = arr[mid/cols][mid%cols];

        if(elem == target)
        {
            return 1;
        }
        if(elem < target)
        {
            s = mid+1;
        }
        else{
            e = mid-1;
        }

    }
    return 0;
}

int SumOfDiagonals(int arr[][4], int rows, int cols)
{
    int d1 = 0, d2 = 0;
    for(int i=0; i<rows; i++)
    {
        for(int j = 0; j<cols; j++)
        {
            if(i == j)
            {
                d1 += arr[i][j];
            }
        }
    }

    int i = 0, j = cols-1;
    while(i< rows && j >= 0)
    {
        d2 += arr[i++][j--];
    }

    return d2;
}

int main()
{
    int arr2[3][4] = {0};
    input2DArray(arr2, 3, 4);
    print2DArray(arr2, 3, 4);
    rowWiseSum(arr2, 3, 4);
    colWiseSum(arr2, 3, 4);
    wavePrint(arr2, 3, 4);
    spiralPrint(arr2, 3, 4);

    rotateMatrix(arr2, 3, 4);
    print2DArray(arr2, 3, 4);

    cout << "is 7 present --> "<< binarySearch2dArr(arr2, 3, 4 ,7) << endl;
    cout << "SubOfDiagonals --> "<< SumOfDiagonals(arr2, 3, 4) << endl;



}