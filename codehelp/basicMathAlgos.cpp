#include <iostream>
#include <vector>
using namespace std;

void printArray(int arr[], int size){
    cout << "Printing array -->" <<endl;
    for(int i=0; i < size; i++)
    {
        cout<< arr[i] << " ";
    }
    cout <<endl<< "-----" << endl;
}

int countPrimeOn(int n)
//sieve of arestothenes
{
    // count primes from 0 to n in Logn2 time complexity
    int count = 0;
    bool prime[(n+1)];
    fill_n(prime, (n+1), true);
    // vector <bool>prime(n+1, true);

    prime[0] = prime[1] = false;

    for(int i=2; i<n; i++)
    {
        if(prime[i])
        {
            count++;
            for(int j = i*2; j<n; j = j+i)
            {
                prime[j] = false; 
            }
        }
    }
    return count;
}

// find gcd using gcd(a-b, b) formula 
// or can use gcd(a%b, b)
int gcd(int a, int b)
{
    while(a != b)
    {
        if(a > b)
        {
            a = a-b;
        }
        else{
            b = b-a;
        }
    }
    return a;
}

void PigeonHoleSort(int InpArr[], int max, int min, int n)
{
    int range = max-min+1;
    vector <int> holeArr[range];

    // holes array
    int index = 0;
    for(int i=0; i<n; i++)
    {
        index = InpArr[i]-min;
        holeArr[index].push_back(InpArr[i]);
    }

    // copy into original array
    index = 0;
    for(int i=0; i<range; i++)
    {
        vector <int>::iterator it;
        for(it = holeArr[i].begin(); it != holeArr[i].end(); ++it)
        {
            InpArr[index++] = *it;
        }
    }
}

// Inclusion Exclusion rule used here
int countDivisible(int n, int a, int b)
{
    // calculate number of integers between 0 to n divisible by a or b

    // number of ints divisible by a
    int c1 = n/a; 

    // number of ints divisible by b
    int c2 = n/b;

    // divisible by both a & b
    int c3 = n/(a+b);

    /// total number of students 
    return (c1+c2-c3);

}

int main()
{
    int n = 10;
    cout << " primes upto "<<n<<" --> "<<countPrimeOn(n) << endl;
    cout << "gcd of 60 & 24 is --> "<< gcd(60, 24) << endl;

    int arr[8] = {8, 2, 4, 7, 6, 3, 5, 8};
    int min = arr[0], max = arr[0];
    for(int i=0; i<8; i++)
    {
        if(arr[i] > max)
        {
            max = arr[i];
        }
        if(arr[i] < min)
        {
            min = arr[i];
        }
    }

    PigeonHoleSort(arr, max, min, 8);
    printArray(arr, 8);
    cout << "using inclusion exclusion, total numbers divisible by 4 or 7 upto 40 -> "<< countDivisible(40, 4, 7) << endl;

}