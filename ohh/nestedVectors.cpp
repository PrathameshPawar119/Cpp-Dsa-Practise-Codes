#include <bits/stdc++.h>
using namespace std;

void printVectorPair(vector<pair<int, int>> v){
    cout << "size: " << v.size() << endl;
    for (int i = 0; i < v.size(); i++)
    {
        cout<< v[i].first << " " << v[i].second << endl;
    } 
}

void printVector(vector<int> v){
    cout <<"size: "<<  v.size() << endl;
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}

int main(){

    //vector of pairs
    vector<pair<int, int>> v;
    for (int i = 0; i < 4; i++)
    {
        v.push_back({i, i*i});
    }
    
    printVectorPair(v);

    // Array of Vectors
    // arr of vectors behaves like 2d vector but here no.of rows is fixed but no.of columns is variable 
    int N;
    cout << "N for av: ";
    cin >> N;
    vector<int> av[N];
    for (int i = 0; i < N; i++)
    {
        int n;
        cin >> n;
        for (int j = 0; j < n; j++)
        {
            int x;
            cin >> x;
            av[i].push_back(x);
        }
    }
    for (int i = 0; i < N; i++)
    {
        printVector(av[i]);
    }


    // Vector of Vectors
    // in vector of vectors both rows and columns are varying

    int len;
    cout<<endl<< "len for vv: ";
    cin >> len;
    vector<vector<int>> vv;
    for (int i = 0; i < len; i++)
    {
        int k;
        cin >> k;
        vector<int> temp;
        // vv.push_back(vector<int> ());  // adding empty vector in parent vector
        for (int j = 0; j < k; j++)
        {
            int t1;
            cin >> t1;
            temp.push_back(t1); // adding elements in subVectors
        }
        vv.push_back(temp);
    }
    // vv[1][1] = 11;
    for (int i = 0; i < vv.size(); i++)
    {
        printVector(vv[i]);
    }
    
    

    
}