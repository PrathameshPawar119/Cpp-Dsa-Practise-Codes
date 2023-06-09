// Odd Set

#include<iostream>
#include<vector>
using namespace std;

int main(){
    int t;
    cin >> t;
    if (t >= 1 && t <= 100)
    {
        while(t--){
            int x;
            cin >> x;
            vector<int> temp;
            bool status = true;
            for (int i = 0; i < 2*x; i++)
            {
                int elem;
                cin >> elem;
                temp.push_back(elem); 
            }
            for (int i = 0; i < temp.size(); i++)
            {
                if (((temp[i]+temp[i+1])%2 == 0)) 
                {
                    status = false;
                    break;
                }
                i++;
            }
            if (status == true)
            {
                cout << "Yes" <<endl;
            }
            else{
                cout << "No" <<endl;
            }
        }
    }
}

