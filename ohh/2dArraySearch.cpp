#include <bits/stdc++.h>
using namespace std;

int main(){

    int x, y;
    cout << "Enter x & y: ";
    cin >> x >> y;

    int arr[x][y];
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            cin >> arr[i][j];
        }
    }

    cout << endl << "Array : \n";
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }

    int key;
    cout <<endl<< "Enter Key: ";
    cin >> key;

    // Searching in 2D array by using 2 loops if it is sorted
    for (int i = 0; i < x; i++)
    {
        int j = 0;
        while (arr[i][j] <= key)
        {
            if (arr[i][j] == key)
            {
                cout<< "1> Found At  Arr-"<<i<<","<<j << endl;
            }
           j++; 
        }
    }

    // Searching 2d Array Using only one loop (like binary search)
    int row = 0, col = y;
    while (row < x && col > 0)
    {
        if (arr[row][col] == key)
        {
            cout << "2> Found At Arr-" << row << "," << col << endl;
            break;
        }
        else if (arr[row][col] > key)
        {
            col--;
        }else{
            row++;
        }
        
    }
    
    
}