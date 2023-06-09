#include <iostream>
using namespace std;

int main(){
    int t;
    cin >> t;
    if(t >=1 && t<=10000){
        while(t--){
            int x;
            cin >> x;
            
            for (int i = int(x/3)-1; i < x; i++)
            {
                if((i*2 + (i+1)*1) == x){
                    cout << i+1 <<" "<< i <<endl;
                    break;
                }
                else if ((i * 1 + (i + 1) * 2) == x)
                {
                    cout << i << " " << i+1 << endl;
                    break;
                }
                else if((i*1 + i*2) == x){
                    cout << i << " " << i << endl;
                    break;
                }
            }
        }
    }
}