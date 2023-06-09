#include <bits/stdc++.h>
using namespace std;



int main(){

    // int x,y;
    // cout << "Enter x & y: ";
    // cin >> x >> y;

    // int arr[x][y];
    // for (int i = 0; i < x; i++)
    // {
    //     for (int j = 0; j < y; j++)
    //     {
    //         cin >> arr[i][j];
    //     }   
    // }
    
    // cout << endl << "Array : \n";
    // for (int i = 0; i < x; i++)
    // {
    //     for (int j = 0; j < y; j++)
    //     {
    //         cout << arr[i][j] << " ";
    //     }
    //     cout << "\n";
    // }

    // cout << endl << "Spiral Output: ";

    // int row_start = 0, row_end = x-1, column_start = 0, column_end = y-1;
    // while (row_start <= row_end && column_start <= column_end)
    // {
    //     // for start row
    //     for (int col = column_start; col <= column_end; col++)
    //     {
    //         cout << arr[row_start][col] << " ";
    //     }
    //      row_start++;

    //     // for column_end
    //     for (int row = row_start; row <= row_end; row++)
    //     {
    //         cout << arr[row][column_end]<< " ";
    //     }
    //     column_end--;

    //     // for row_end
    //     for (int col = column_end; col >= column_start; col--)
    //     {
    //         cout << arr[row_end][col] << " ";
    //     }
    //     row_end--;

    //     // for start column
    //     for (int row = row_end; row >= row_start; row--)
    //     {
    //         cout << arr[row][column_start] << " ";
    //     }
    //     column_start++;
         
    // }

    // cout << "Transpose of matrix: \n";
    // for (int i = 0; i < y; i++)
    // {
    //     for (int j = 0; j < x; j++)
    //     {
    //         swap(arr[i][j], arr[j][i]);
    //         cout << arr[i][j] << " ";
    //     }
    //     cout << "\n";
    // }



    //For Matrix Multiplication **********************************************
    int a, b, c;
    cout << endl << "Enter a, b, c fro matrix mutiplicatn: ";
    cin >> a>> b>> c;

    int mat1[a][b];
    int mat2[b][c];

    // Getting Input of both matrices
    cout << "Enter Matrix 1 : " << a << " X " << b << endl;
    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < b; j++)
        {
            cin >> mat1[i][j];
        }
    }
    cout << "Enter Matrix 2: " << b << " X " << c << endl;
    for (int i = 0; i < b; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> mat2[i][j];
        }
    }

    // Predefining answer array by making all elems 0
    int ans[a][c];
    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < c; j++)
        {
            ans[i][j] = 0;
        }
    }

    // plotting addition of row x col multiples into ans matrix
    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < c; j++)
        {
            for (int k = 0; k < b; k++)
            {
                ans[i][j] += mat1[i][k]*mat2[k][j];
                // here for multiplication of each element innermost loop must be with both matrices
                // and i and j are for positions only 
                // so mat1 and mat2 are both included k loop and 1 diff loop
            }   
        }
    }
    
    // Plotting answer
    cout << endl << "Ans Matrix: "<< endl;
    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}