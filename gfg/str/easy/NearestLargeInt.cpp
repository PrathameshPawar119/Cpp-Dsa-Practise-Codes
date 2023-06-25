#include <iostream>
#include <typeinfo>
#include <string>
using namespace std;


// Compute the nearest larger number by interchanging its digits updated.Given 2 numbers a and b find the
//  smallest number greater than b by interchanging the digits of a and if not possible print -1.
// Sample Input:
//     459 500
// Sample Output:
//     549

int toInt(string temp)
{
    int num = stoi(temp);
    return num;
}

string toStr(int temp)
{

    string str = to_string(temp);
    return str;
}

int ComputeNearestLargstInt(int a, int b)
{
    int num1, num2;
    if(a>b)
    {
        num1 = b;
        num2 = a;
    }
    else{
        num1= a;
        num2= b;
    }

    string str1 = toStr(num1);

    for(int i=0; i< str1.length()-1; i++)
    {
        if(toInt(str1) > num2)
        {
            int temp = toInt(str1);
            return temp;
        }
        swap(str1[i], str1[i+1]);
    }

    return -1;
}

int main(){

    // int num1 = 645757;
    // int num2 = 457765;
    int num1 = 459;
    int num2 = 500;

    cout << "ComputeNearestLargstInt(num1, num2) --> " << ComputeNearestLargstInt(num1, num2);
}