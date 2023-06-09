#include <bits/stdc++.h>
#include <string.h>
using namespace std;

string toUpper(string str){
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] >= 'a' && str[i] <= 'z')
        {
            str[i] -= 32;
            // difference between ascii vaues of capita; and small is 32
        }
    }
    return str;
}

string toLower(string str){
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
        {
            str[i] += 32;
            // to move their positions to capitals 
        }
    }
    return str;
}

void MostFrequentChar(string str){
    int maxim = INT_MIN;
    char maxChar;
    for (int i = 0; i < str.size(); i++)
    {
        int currMax = 0;
        for (int j = 0; j < str.size(); j++)
        {
            if (str[i] == str[j])
            {
                currMax++;
            }   
        }
        if (currMax > maxim)
        {
            maxim = currMax;
            maxChar = str[i];
        }
    }
    
    cout << maxChar <<" appeared " << maxim << " times \n";
}


int main(){
    string s1 = "Prathamesh";
    string s3 = "hij";
    string s2(3, 'g'); // to multiply char 'o' 3 times

    cout << s2 << endl;

    s1.append(s2);
    cout << s1 << endl;

    s1.clear();
    cout << s1 << endl;

    cout << s2.compare(s3) << endl;

    string s4 = "WhoKNowsNext";
    s4.erase(3,4);
    cout << s4 << endl;
    s4.insert(3, "Is");
    cout << s4 << endl;

    string s5 = s4.substr(3,2);
    cout << s5 << endl;

    string s6 = "124";
    int t1 = stoi(s6);   // string to number
    cout << typeid(s6).name() << " : " << typeid(t1).name() << endl;


    // HO wto sort an string in speciific interval or all string

    string s7 = "PrathameshPawar";
    sort(s7.begin(), s7.end());   // sort (first, last)
    cout << s7 << endl;
    cout << s7.size() << endl;

    cout << toUpper(s7) << endl;
    cout << toLower(s7) << endl;


    // Find the biggest number from number string
    string numStr = "5678792";
    sort(numStr.begin(), numStr.end());
    // sort(numStr.begin(), numStr.end(), greater<int>()); // to sort descreasing order
    cout << "Biggest Num:" << numStr[numStr.length()-1] << endl;

    MostFrequentChar(s7);


}