#include <bits/stdc++.h>
using namespace std;

bool CheckPalindrome(char arr[], int n){
      for (int i = 0; i < (n/2); i++)
      {
        if (arr[i] != arr[n-i-1])
        {
            return false;
        }  
      }
    return true;
}

int CheckBiggestWord(char arr[])
{
    int i = 0;
    int currLen = 0, maxLen = 0;
    int st=0, maxst=0;
    while (1)
    {
        if (arr[i] == ' ' || arr[i] == '\0')   
        {
            if (currLen > maxLen)
            {
                maxLen = currLen;
                maxst = st;
            }
            currLen = 0;
            st = i+1;
        }
        
        currLen++;
        if (arr[i] == '\0')
        {
            break;
        }
        i++;
    }

    for (int i = 0; i < maxLen; i++)
    {
        cout << arr[i+maxst];// maxst = from where to start
    }

    return maxLen-1;
}


int main(){
    char word[100] = "Prathamesh";
    int i = 0;
    while (word[i] != 0)
    {
        cout << word[i] << " ";
        i++;
    }

    cout <<endl<< "Enter Word: ";
    cin.getline(word, 100);
    cout << word;

    cout << " " << CheckPalindrome(word, strlen(word));
    cout<<endl<< "Len of biggest word: " <<CheckBiggestWord(word);

}