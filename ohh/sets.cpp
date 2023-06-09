#include <bits/stdc++.h>
using namespace std;

void printSet(set<string> s){
    cout << endl;
    for(string value : s){
        cout << value << " ";
    }
    cout<<endl;
}

void printMultiSet(multiset<string> ms)
{
    for (auto value : ms)
    {
        cout << value << " ";
    }
    cout << endl;
}

int main(){
    set <string> s;
    s.insert("abc");
    s.insert("pawar");
    s.insert("xyz");
    s.insert("popo");
    s.insert("pawar");  // set presserves uniqueness of elements same as map

    auto it = s.find("pawar");
    if (it != s.end())
    {
        cout << (*it);
        s.erase(it);
    }
    printSet(s);

    // multistate - In Set duplicate values are not allowed to get stored. On other hand in case of MultiSet we can store duplicate values
    multiset <string> ms;
    ms.insert("how");
    ms.insert("are");
    ms.insert("are");
    ms.insert("you");
    ms.insert("you");

    printMultiSet(ms);

    auto it2 = ms.find("you");
    if (it2 != ms.end())
    {
        ms.erase(it2); // it will delete only one "you" - one iteration
    }
    ms.erase("are"); // it deletes all "are" iterations

    printMultiSet(ms);
  
    
}