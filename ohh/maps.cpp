#include <bits/stdc++.h>
using namespace std;

void printMap(map <int, int> m){
    int size = m.size();
    cout <<endl<< "Size: "<< size<<endl;
    for(auto value : m){
        cout<< value.first << " "<< value.second << endl;
    }

}

int main(){

    // Map is just like vector of pairs which orders automatically with logn time co
    map<int, int> m;
    m[1] = 11;
    m[4] = 44;
    m[5];  // if you put it blank then it declares 0 as val
    m.insert({2, 22});

    // printing map using Iterator
    map <int, int> :: iterator it;
    for ( it = m.begin(); it != m.end(); it++)
    {
        cout << (*it).first <<" "<< (*it).second << endl; 
    }

    //Printing map using auto
    for(auto &value : m){  // by adding & it couts actual values don't creates copy
        cout<< value.first <<" "<< value.second <<endl;
    }

    m.erase(2);
    printMap(m);

    // Print frequencies of inputted names
    map <string, int> ms;
    int n;
    cout<< "Enter n: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        ms[str] = ms[str]+1; //ms[key] = value+1
    }
    for(auto pr: ms){
        cout << pr.first << " - "<< pr.second  << endl;
    }

    //Unordered Map  where order order is not maintained
    // here hash is created for each key and on hash basis they are ordered.  O(n)
    // it removes duplicates automatically
    unordered_map<int, int> um;
    int temp;
    cout <<endl<<"Enter lenth for um: ";
    cin >> temp;
    for (int i = 0; i < temp; i++)
    {
        int x, y;
        cin >> x >> y;
        um[x] = y;
    }
    for(auto value: um){
        cout<< value.first<<" "<< value.second <<endl;
    }
    
    
    

}