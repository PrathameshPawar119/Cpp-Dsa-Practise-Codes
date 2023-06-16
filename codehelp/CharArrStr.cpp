#include <iostream>
#include <vector>
#include <algorithm>
// #include <stack>
using namespace std;

void printArray(int arr[], int size){
    cout << "Printing array -->" <<endl;
    for(int i=0; i < size; i++)
    {
        cout<< arr[i] << " ";
    }
    cout <<endl<< "-----" << endl;
}
void printVector(vector <char> arr){
    cout << "Printing array -->" <<endl;
    for(int i=0; i < arr.size(); i++)
    {
        cout<< arr[i] << " ";
    }
    cout <<endl<< "-----" << endl;
}

char toLowerChar(char ch)
{
    if(ch <= 'z' && ch >= 'a')
    {
        return ch;
    }
    else{
        char temp = ch - 'A' + 'a';
        return temp;
    }

}

void countFrequency(string s)
{

}
s
// alphabetically count the number of frequency of letter in words
void countFrequencyAlphabetically(string s)
{
    int arr[26] = {0};
    vector <char> v;
    for(int i=0; i<s.length(); i++)
    {
        int index = toLowerChar(s[i]) - 'a';
        arr[index]++;
    }

    for(int i=0; i<26; i++)
    {
        char ch = i + 'a';
        if(arr[i] >=1)
        {
            v.push_back(ch);
            if(arr[i] > 1)
            {
                string temp = to_string(arr[i]);
                // now temp is iterator so, get value by itterating it for(char ch: tmep)
                for(char ch: temp)
                {
                    v.push_back(ch);
                }
            }
        }
    }

    printVector(v);
    // printArray(arr, 26);
}


void mostRepeatedCharofStr(string s)
{
    // create array of 26 zeroes
    int abcd[26] = {0};
    // assume each index as 26 abcd and ++ when detected  
    for(int i=0; i<s.length(); i++)
    {
        // get index from lowercased alphabet by ch- 'a'
        int index = toLowerChar(s[i]) - 'a';
        abcd[index] += 1;
    }

    int max = INT_MIN;
    int charPosition =0;
    // find max repeated and position
    for(int i=0; i<26; i++)
    {
        if(abcd[i] > max)
        {
            max = abcd[i];
            charPosition = i;
        }
    }

    // get char from positoin from array
    char ans = charPosition + 'a';
    cout <<endl<< ans << " repeated atmost " << max << " times" <<endl;
}

string reverseStrNotWords(string s)
{
    reverse(s.begin(), s.end());
    s.insert(s.end(), ' ');

    int j = 0;

    for(int i=0; i<s.length(); i++)
    {
        if(s[i] == ' ')
        {
            reverse(s.begin()+j, s.begin()+i);
            j= i+1;
        }
    }

    s.pop_back();

    return s;
}


bool isValidChar(char ch)
{
    // Function to identify valid char̥acter
    if((ch >= 'a' && ch <= 'z') || 
        ( ch >= 'A' && ch <= 'Z') || 
        (ch >= '0' && ch <= '9'))
    {
        return true;
    }
    return false;
}

void tolowercase(char word[], int size)
{
    for(int i=0; i<size; i++)
    {
        if(word[i] >= 'a' && word[i] <= 'z')
        {
            continue;
        }
        else{
            char temp = word[i] - 'A' + 'a';
            word[i] = temp;
        }
    }
}

bool checkPalindrome(char elem[], int size)
{
    for(int i=0; i<size/2; i++)
    {
        if(elem[i] != elem[size-i-1])
        {
            return false;
        }
    }
    return true;
} 

int strLen(char elem[])
{
    int len = 0;
    int i=0;
    while(elem[i] != '\0')
    {
        len++;
        i++;
    }
    return len;
}

int main()
{
    // '\0' is null, placed at end of every string in char array
    //  like -> Pawar --> |P|a|w|a|r|\0|||||||||...
    char name[20];
    cout << "Enter Name -> ";
    cin >> name;
    // name[3] = '\0'; 

    int len = strLen(name);
    cout << "Length -> "<< len <<endl;
    cout << "isPalidrome -> "<< checkPalindrome(name, len) << endl;
    tolowercase(name, len);
    cout << "to Lowercase -> "<< name << endl;

    string str("aaabbbcccdee");
    cout <<endl<< "reverseStrNotWords -->"<< reverseStrNotWords(str) << endl;
    mostRepeatedCharofStr(str);
    countFrequencyAlphabetically(str);
}