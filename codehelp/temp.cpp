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
     bool countEvenOdds(string s)
    {
        int arr[26] = {0};
        for(int i=0; i<s.length(); i++)
        {
            int index = s[i] - 'a';
            arr[index] += 1;
        }
        printArray(arr, 26);
        
        int evens = 0, odds = 0, alphabets = 0;
        for(int i=0; i<26; i++)
        {
            if(arr[i]%2 == 0)
            {
                evens++;
            }
            else{
                odds++;
            }
            if(arr[i]!=0)
            {
                alphabets++;
            }
        }
        cout << " alphs- "<<alphabets<<endl;
        
        if(odds > 1 || evens < alphabets-1)
        {
            return false;
        }
            cout << evens << "-"<<odds<< endl;
        return true;
    }

int main() {
    // Example usage
    // vector<int> p = {4, 5, 2, 6};
    // vector<int> h = {1, 3, 2, 4};
    cout << "countEvenOdds--> " << countEvenOdds("bbcbabccw") << endl;
    
    return 0;
}