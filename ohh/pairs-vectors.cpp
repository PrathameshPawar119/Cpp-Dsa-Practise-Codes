#include<bits/stdc++.h>
using namespace std;

void printVec(vector <int> v){
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}

int main(){

    // Pairs ---->
    pair<int, string> p1;
    p1 = {1, "Prathamesh"};

    pair<int, string> p2 = p1;  // this is call by value, here both p1 & p2 are different
    // pair<int, string> &p2 = p2; // call by reference whenever er change p2 it changes directly into p1
    p2.first = 22;

    cout << p1.first << " " << p1.second << endl;
    cout << p2.first << " " << p2.second << endl;

    // Pair Array
    pair<int, int> p_arr[3]; // array of pairs
    p_arr[0] = {1,3};
    p_arr[1] = {2,6};
    p_arr[2] = {3,9};

    swap(p_arr[0], p_arr[2]);


    for (int i = 0; i < 3; i++)
    {
        cout << p_arr[i].first <<" "<< p_arr[i].second <<endl;
    }
    

    // Vectors ----->
    // initializing vector manually with any size
    vector <int> v1;
    for (int i = 0; i < 6; i++)
    {
        v1.push_back(i);
    }
    printVec(v1);

    // initializing vector with fix size but it is variable
    vector <int> v2(8, 3);
    printVec(v2);

    v2.push_back(43);
    printVec(v2);

    v2.pop_back();
    printVec(v2);




    return 0;

}