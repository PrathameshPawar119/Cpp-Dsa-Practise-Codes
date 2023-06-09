#include <bits/stdc++.h>
using namespace std;

// To find largest from array
int largest(int a[], int n){
    int max = a[0];
    for (int i = 1; i < n; i++)
    {
        if (a[i] > max)
        {
            max = a[i];
        }  
    }
    return max;
}

int sqr(int n){
    return n*n;
}


//Function for Sum upto n elements
int sumUpto(int n){
    int a = 1;
    return (n*(n+1))/(2*a);
}

//Function to check given triplet is pythagorian triplet
int PythagorianTriplet(int arr[]){
    int left = sqr(largest(arr, 3));
    int right = sqr(arr[0])+sqr(arr[1])+sqr(arr[2]) - sqr(largest(arr, 3));
    if (left == right)
    {
        return true;
    }
   return false;    
}

int BinaryToDec(int n){
    int ans = 0;
    int i = 0;
    int lastDigit;
    while (n > 0)
    {
        lastDigit = n%10;
        ans += lastDigit * pow(2, i) ;
        i += 1;
        n = n/10;
    }
    return ans;
}

int DecToBinary(int n){
    string ans ;
    int i = 0;
    int temp;
    while (n)
    {
        temp = n%2;
        if (temp & 1){
            ans.append("1");
        }
        else{
            ans.append("0");
        }
        n = n/2;
    }
    cout << ans << endl;
    return 0;
}

string HexaToDec(string n){
    string ans;
    int temp = 1;
    int s = n.size();
    for (int i = s-1; i >= 0; i--)
    {
        if (n[i] >= '0' && n[i] <= '9')
        {
            ans += temp*(n[i] - '0');
        }
        else if(n[i] >= 'A' && n[i] <= 'F')
        {
            ans += temp*(n[i]-'A' + 10);
        }
        temp *= 16;
    }
    return ans; 
}
              
    
int main(){
    // cout << sumUpto(5);

    int arr1[] = {3,4,5};
    cout << PythagorianTriplet(arr1) << endl;

    cout << BinaryToDec(1111) << endl;
                // 1 2 4 8 16 32 64 
     DecToBinary(15) ;

    cout << HexaToDec("1CF") << endl;

}