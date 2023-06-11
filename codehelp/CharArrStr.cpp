#include <iostream>
using namespace std;


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

}