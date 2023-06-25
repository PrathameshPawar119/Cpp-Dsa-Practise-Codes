#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

bool isPalindrome(string str)
{
    // O(n/2)
    for(int i=0; i<str.length()/2; i++)
    {
        if(str[i] != str[str.length()-i-1])
        {
            return false;
        }
    }
    return true;
}

void findPalindrome(string str)
{
    // function to find palindrome in given string O()
    cout << "Palindromes in string "<< str << " are  --> ";
    for(int i = 0; i< str.length(); i++)
    {
        for(int j = i+1; j< str.length(); j++)
        {
            if(str[i] == str[j] && i!=j)
            {

                if(isPalindrome(str.substr(i, j-i+1)))
                {
                    string s1 = str.substr(i, j-i+1);
                    cout << s1 << " ";
                    // return str.substr(i, j);
                }
            }
        }
    }

    // return "No Palindrome!";
}

// Count of permutations such that sum of K numbers from given range is even
int CountEvenSumPermutations(int l, int h, int k)
{
    // find total even and odds
    int even_count = h/2 - (l-1)/2;
    int odd_count = (h+1)/2 - l/2;

    // intialize even_sum & odd_sum
    int even_sum = 1;
    int odd_sum = 0;

    for(int i=0; i<k; i++)
    {
        int prev_even = even_sum;
        int prev_odd = odd_sum;

        even_sum = (prev_even * even_count) + (prev_odd * odd_count);
        odd_sum = (prev_even * odd_count) + (prev_odd * even_count);
    }

    return even_sum;
}

int main()
{
    string a1 = "nayan";
    cout << "isPalindrome(nayan) ? --> " << isPalindrome(a1) << endl;
    findPalindrome("bnayananamansal");

    cout <<endl<< "count of permutations from 1 to 10 by k=2 is --> " << CountEvenSumPermutations(1, 10, 2) << endl;



    
}