#include <iostream>
using namespace std;

int main(){

    int a;
    cout << "Enter a:";
    cin >> a;

    //inverted number triangle (i = column number)
    // for(int i=1; i<= a; i++){
    //     for(int j=a; j>= i; j--){
    //         cout << j <<" ";
    //     }
    //     cout << "\n";
    // }

    // alternate binary number triangle
    // for(int i=1; i<=a; ++i){
    //     for(int j=1; j<=i; ++j){
    //         if ((i+j)%2 == 0)
    //         {
    //             cout << 1 <<" ";
    //         }
    //         else
    //         {
    //             cout << 0 <<" ";
    //         }
    //     }
    //     cout << "\n";
    // }

    //Rhombus Pattern
    // for (int i = 0; i < a; i++)
    // {
    //     for (int j = 0; j < a-i-1; j++)
    //     {
    //         cout << " ";
    //     }
        
    //     for (int i = 0; i < a; i++)
    //     {
    //         cout << "* ";
    //     }
    //     cout <<endl;   
    // }

    //Triangle Number Pattern
    // for (int i = 0; i < a; i++)
    // {
    //     for (int k = 0; k < a-i-1; k++)
    //     {
    //         cout << " ";
    //     }
    //     for (int j = 0; j <= i; j++)
    //     {
    //        cout << j+1 << " "; 
    //     }
    //     cout <<endl;
    // }
    
    //Palindrome pattern
    // for (int i = 0; i < a; i++)
    // {
    //     int j;
    //     for ( j = 0; j < a-i-1; j++)
    //     {
    //         cout << " ";
    //     }
    //     int k = i;
    //     for ( ; j < a; j++)
    //     {
    //         cout << (k--)+1 ;
    //     }
    //     for (int l = 1; l <= i; l++)
    //     {
    //        cout << l+1;
    //     }
    //     cout << endl;
    // }

    //Star Kite Pattern
    // for (int i = 0; i < a; i++)
    // {
    //     for (int j = 0; j < a-i; j++)
    //     {
    //         cout << "  ";
    //     }
    //     for (int j = 0; j < 2*i-1; j++)
    //     {   
    //         cout << "* ";
    //     }
    // cout << "\n";
    // }
    // for (int i = a; i > 0; i--)
    // {
    //     for (int j = 0; j < a - i; j++)
    //     {
    //         cout << "  ";
    //     }
    //     for (int j = 0; j < 2 * i - 1; j++)
    //     {
    //         cout << "* ";
    //     }
    //     cout << "\n";
    // }

    //Star M-Pattern
    for (int i = 1; i <= 3; i++)
    {
        for (int j = 1; j <=9; j++)
        {
            if ((i+j)%4 == 0 || (i==2 && j%4==0))
            {
                cout << "* ";
            }
            else{
                cout << "  ";
            }
            
        }
        cout << endl;
        
    }
    
}