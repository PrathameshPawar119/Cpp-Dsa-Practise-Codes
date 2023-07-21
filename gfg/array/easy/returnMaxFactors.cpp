#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void printVector(vector <int> vec){
    int size = vec.size();
    cout << "Printing vector -->" <<endl;
    for(int i=0; i < size; i++)
    {
        cout<< vec[i] << " ";
    }
    cout <<endl<< "-----" << endl;
}


void findMaxFactors(int n, vector <int>& ans)
{
    if(n < 10)
    {
        ans.push_back(n);
        return;
    }

    for(int i=9; i>2; i--)
    {
        if(n%i == 0)
        {
            n = n/i;
            ans.push_back(i);
        }
    }
    findMaxFactors(n, ans);
}

int main()
{
    int n = 0;
    cin >> n;

    vector <int> ans;
    findMaxFactors(n, ans);
    sort(ans.begin(),ans.end());
    printVector(ans);


}