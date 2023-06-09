#include <bits/stdc++.h>
using namespace std;

void printvec(vector <int> v){
    for(auto val: v){
        cout << val << "-";
    }
}

int kthMex(int N, int K, int A[])
{
    int maxi = INT_MIN;

    for (int i = 0; i < N; i++)
    {
        maxi = max(A[i], maxi);
    }

    vector<int> v2;
    for (int i = 0; i <=  maxi*5+1; i++)
    {
        v2.push_back(i);
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < (v2.size())/3; j++)
        {
            if (A[i] == v2[j])
            {
                v2.erase(v2.begin() + j);
            }
        }
    }
    printvec(v2);
    cout << endl;
    if (v2[K - 1] == 0)
    {
        return 1;
    }
    
    return (v2[K - 1]);
}

int main()
{
    int N = 1;
    int A[N] = {0};
    int K = 1;

    int ans = kthMex(N, K, A);
    cout << ans;
    
}