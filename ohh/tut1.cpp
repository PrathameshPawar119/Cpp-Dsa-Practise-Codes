#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int c = 12;
int main(){
    cout << "Good NIght" << endl << "Morning" << endl;
    cout << powl(3,3) << endl;

    int a;
    cin >> a;
    int c = 2*a;
    cout << "local c = " << c << endl;
    cout << "global c = " <<setw(4)<< ::c << endl;
    ::c = ::c+4;
    cout << "global c = " <<setw(4)<< ::c << endl;
    int & d = a; // therefore now d == a
    cout << d << endl;

    int* temp1 = &a;
    int ** temp2 = &temp1;
    // int *** temp3 = &temp2;
    cout << "Address of a = "<< temp1 << endl;
    cout << "Address of pointer temp1 = "<< temp2 << endl;
    cout << "Value at addrress temp1 = "<< *temp1 << endl;
}