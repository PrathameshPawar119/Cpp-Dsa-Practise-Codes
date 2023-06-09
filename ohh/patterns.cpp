#include <iostream>

using namespace std;

int main(){

    int a, b;
    cout << "\nEnter a:";
    cin >> a ;
    cout << "\nEnter b:";
    cin >> b ;
    cout << "\n";

    // Hollow Rectangle
    // for(int i=0; i < a; i++){
    //     for(int j=0; j < b; j++){
    //         if (i==0 || i==a-1){
    //             cout << "* ";
    //         }
    //         else{
    //             if (j==0 || j==b-1){
    //                 cout << "* " ;
    //             }
    //             else{
    //                 cout << "  ";
    //             }  
    //         }
    //     }
    //     cout << "\n";
    // }

    // Inverted Triangle
    // for(int i = a; i > 0; i--){
    //     for(int j = i ; j > 0 ; j--){
    //         cout << "* ";
    //     }
    //     cout << "\n";
    // }
    
    // Half pyramid rotated
    // for (int i=1; i<= a; i++){
    //    for(int j=1; j<= a ; j++){
    //         if(j <= a-i ){
    //             cout << "  ";
    //         }
    //         else{
    //             cout << "* ";
    //         }
    //    }
    //    cout << "\n";
    // }

    //half pyramid using numbers
    // for(int i=1; i<= a; i++){
    //     for (int j=1; j <= a; j++){
    //         if(j <= i){
    //             cout << i;
    //         }
    //     }
    //     cout << "\n";
    // }

    // Butterfly Pattern
    for(int i=1; i<= a; i++){
        for(int j=1; j<= i; j++){
            cout << "* ";
        }
        int spaces= 2*a-2*i;
        for(int k=1; k<= spaces; k++){
            cout << "  ";
        }
        for(int j=1; j<= i; j++){
            cout << "* ";
        }
        cout << "\n";
    }
    for(int i=a; i>= 1; i--){
        for(int j=1; j<= i; j++){
            cout << "* ";
        }
        int spaces= 2*a-2*i;
        for(int k=1; k<= spaces; k++){
            cout << "  ";
        }
        for(int j=1; j<= i; j++){
            cout << "* ";
        }
        cout << "\n";
    }
    
}