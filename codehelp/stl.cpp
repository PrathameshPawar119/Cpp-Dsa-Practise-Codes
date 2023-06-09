#include <iostream>
#include <array>
#include <vector>
#include <deque>
#include <list>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
using namespace std;


int main()
{
    // size - current elements 
    // capacity -total size or capacity

    // STL Array
    array <int, 5>  arr = {2,4,3, 6,7};

    cout << "size - "<< arr.size() << endl;
    cout << "First- "<< arr.front() << endl;
    cout << "Last- "<< arr.back() << endl;
    cout << "2nd Position- "<< arr.at(2) << endl;
    cout << "IsEmpty- "<< arr.empty() << endl << endl;



    // Vector
    // vector doubles its capacity whenever we try to add extra element to it // 
    vector <int> vect = {2, 7,6};
    cout << "capacity - " << vect.capacity() << endl;
    vect.push_back(4);
    cout << "capacity - " << vect.capacity() << endl;
    cout << "size - " << vect.size() << endl;
    // clear do empty array by doing size=0 but capacity remains same
    vect.clear();
    cout << "capacity after clear - " << vect.capacity() << endl;
    cout << "size after clear - " << vect.size() << endl <<endl;

    vector <int> vect2 (5, 2); // initialize 5 times 2



    // Deque - double ended queue
    deque <int> d;
    d.push_back(2);
    d.push_front(5);
    cout << "d.at(0) is " << d.at(0) << endl <<endl;

    
    //List 
    // list does not have direct access like array, vector, deque
    list <int> l;
    l.push_back(4);
    l.push_front(8);

    list <int> nl(l);
    //  way to access list elements for(int i:list)
    for (int i:nl)
    {
        cout << i <<" ";
    }

    // Stack
    stack <int> st;
    st.push(4);
    st.push(9);
    cout <<endl << "Stack top - " << st.top() << endl;
    st.pop();
    cout << "Stack top - " << st.top() << endl<<endl;



    // Priority Queue
    // priority queue automatically sorts given elements
    // two type min priority queue and maximum priority quque
    // Queue also cannot be accesed directly like list

    // Max heap
    priority_queue <int> maxq;

    // Min heap
    priority_queue <int, vector <int>, greater<int>> minq;

    maxq.push(1);
    maxq.push(4);
    maxq.push(8);
    maxq.push(0);

    int n = maxq.size();  // it decreases dynamically
    for(int i=0; i< n; i++)
    {
        cout << maxq.top() << " ";
        maxq.pop();
    } cout << endl;

    minq.push(1);
    minq.push(4);
    minq.push(8);
    minq.push(0);

     n = minq.size();  // it decreases dynamically
    for(int i=0; i< n; i++)
    {
        cout << minq.top() << " ";
        minq.pop();
    } cout << endl<<endl;


    //SET
    // set dosen't includes duplicates
    // default ascending order
    // set also cannot be directly accessed like list
    cout << "SET -- >" << endl;
    set <int> set1 = {2, 3, 1};
    set1.insert(4);
    set1.insert(4);

    for(int i:set1)
    {
        cout << i << " ";
    }cout << endl;

    set1.erase(++set1.begin());

    for(int i:set1)
    {
        cout << i << " ";
    }cout << endl;

    cout << "Elem present ? " << set1.count(3) << endl<<endl;

    // Find position of element using iterator in set
    // set <int> ::iterator itr = set1.find(3); // itr is iterator must be printed in loop



    // Map
    // map is key value pair dictionary
    cout << "Map -->" << endl;
    map <string, string> mp1;
    mp1["Prathamesh"] = "Pawar";
    mp1["Rutya"] = "Don";

    mp1.insert({"Luv", "Babbar"});

    for(auto i:mp1)
    {
        cout << i.first<< " - " << i.second << endl;
    }
    cout << "Is present Rutya " << mp1.count("Luv") << endl;
    // mp1.erase("Luv");

    auto it = mp1.find("Rutya");
    for(auto i=it; i!= mp1.end(); i++)
    {
        cout << (*i).first << " ";
    } cout << endl<<endl;




    // Algorithms
    cout << "Algorithms ---> "<< endl;
    vector <int> vecto = {2, 3, 4, 5, 6, 7};

    cout << " 2 present by bs ? " << binary_search(vecto.begin(), vecto.end(), 2)<< endl;
    //  max(vect[2], vect[4]);
    string abcd = "abcd";
    reverse(abcd.begin(), abcd.end());
    cout << "abcd --> " << abcd << endl;

    vector <int> temp2 = {4, 3, 2, 8};
    // quicksort + heapsort + insertion sort = introsort
    // this introsort is used here
    sort(temp2.begin(), temp2.end());
    // rotate()
}