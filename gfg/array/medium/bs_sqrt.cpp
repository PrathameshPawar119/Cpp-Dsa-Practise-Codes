#include <iostream>
using namespace std;

// Find Square root of number using binary search
long long int BSSqrt(int target)
{
    int s = 0;
    int e = target;
    long long int ans = -1;
    long long int sqr = 0;

    while(s < e)
    {
        long long int mid = s+(e-s)/2;
        // if(mid < INT_MAX/mid || mid > INT_MIN/mid){
        sqr = mid*mid;
        // }
        if(sqr == target)
        {
            return mid;
        }
        if(sqr < target)
        {
            ans = mid;
            s = mid;
        }
        else{
            e = mid;
        }
    }
    return ans;
}

double morePrecision(int n, int precision, int temp)
{
    double factor = 1;
    double ans = temp;

    for(int i=0; i<precision; i++)
    {
        factor = factor/10;

        for(double j=ans; j*j < n; j= j+factor)
        {
            ans = j;
        }
    }
    return ans;
}

int main()
{
    int target = 68;

    int tempSoln =  BSSqrt(target);

    // cout << "tempSoln = "<< tempSoln <<endl;
    cout << "sqrt --> " << morePrecision(target, 3, tempSoln)<<endl;

    return 0;
}