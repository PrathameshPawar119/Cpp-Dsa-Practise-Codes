#include <iostream>
#include <vector>
using namespace std;

void printArray(int arr[], int size){
    cout << "Printing array -->" <<endl;
    for(int i=0; i < size; i++)
    {
        cout<< arr[i] << " ";
    }
    cout <<endl<< "-----" << endl;
}

void printVector(vector <int> vec){
    int size = vec.size();
    cout << "Printing vector -->" <<endl;
    for(int i=0; i < size; i++)
    {
        cout<< vec[i] << " ";
    }
    cout <<endl<< "-----" << endl;
}

void printStrVector(vector <string> vec){
    int size = vec.size();
    cout << "Printing vector -->" <<endl;
    for(int i=0; i < size; i++)
    {
        cout<< vec[i] << " ";
    }
    cout <<endl<< "-----" << endl;
}

int BS(int arr[], int s, int e, int target)
{
    while(s<e)
    {
        int mid = (s+e)/2;
        if(arr[mid] == target)
        {
            return mid;
        }      
        if(arr[mid] > target)
        {
            e = mid-1;
        }
        else
        {
            s = mid+1;
        }
    }
    return -1;
}