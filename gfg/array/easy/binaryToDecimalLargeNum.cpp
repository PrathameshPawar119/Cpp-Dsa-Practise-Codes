#include <iostream>
#include <math.h>
using namespace std;

string decimalToBinary(int n)
{
    string ans = "";
    while(n)
    {   int rem = n%2;
        ans += to_string(rem);
        n /= 2;
    }
    return ans;
}

<<<<<<< HEAD
void ReverseBinary(string& binary) // this is 32 bit reverse
=======
void ReverseBinary(string& binary)
>>>>>>> e472a299320487c84230dd2702ddbc2e5f9f5abd
{
    for(int i = binary.length(); i < 32; i++)
    {
        binary += '0';
    }
}

long long int binaryTodecimal(string& binary)
{
    long long int ans = 0;
    for(int j = binary.length()-1; j >= 0; j--)
    {
        if(binary[j] == '1')
        {
            ans += pow(2,binary.length()-j-1 );
        }
    }
    return ans;
}


int main()
{
    int num  = 1;
    string ans = decimalToBinary(num);
    cout << "decimalToBinary(num)  -> "  << ans<<endl;
    ReverseBinary(ans);
    cout<< "ReverseBinary(ans)  -> "<<ans<<endl;
    long long int deci = binaryTodecimal(ans);
    cout << deci;


}