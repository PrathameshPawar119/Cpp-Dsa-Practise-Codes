#include<bits/stdc++.h>
using namespace std;


int main(){

    // Iterating over Vector
    vector<int> v = {1,2,3,4,5};
    vector<int> :: iterator it = v.begin(); //  Initialization of vector
    for ( it = v.begin(); it < v.end(); it++)
    {
        cout << *it <<" ";
    }
    cout << endl;

    // Iterating Over Vector of pairs
    vector <pair<int, int>> vp = {{1,1}, {2,2}, {3,3}};
    // vector <pair<int, int>> :: iterator it2 = vp.begin(); 
    for ( auto it2 = vp.begin(); it2 < vp.end(); it2++)
    {
        cout << (it2 -> first) << " "<< (it2 -> second) << endl;
    }
    for ( auto it2 = vp.begin(); it2 < vp.end(); it2++)
    {
        cout << (*it2).first << " " << (*it2).second << endl;
    }


    // How to write Iterators in short
    // iterating over vector
    for(int value : v){
        cout << value << " ";
    }
    cout << endl;
    for(int &value : v){
        value++;
        cout << value << " ";
    }
    cout << endl;

    // Iterating Over vector of pairs
    for( pair<int, int> value: vp){
        cout << value.first << " " << value.second << endl;
    }
    // same above but using auto
    for (auto value : vp){
        cout << value.first << " " << value.second << endl;
    }
}