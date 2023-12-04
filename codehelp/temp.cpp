#include<iostream>
#include <vector>
#include<stack>
#include <algorithm>
#include "../gfg/array/default_funcs.cpp"
using namespace std;

// find unique element in array where  other elements are repwated exactly twice
int findUnique1(int arr[], int n)
{
    int uniq = 0;
    for(int i = 0; i < n; i++)
    {
        uniq = uniq ^ arr[i];
    }
    return uniq;
}

vector <int> find2Uniques(int arr[], int n)
{
    int uniq = 0;
    for(int i = 0; i < n; i++)
    {
        uniq = uniq ^ arr[i];
    }

    vector<int> ans;
    int a = uniq, b= uniq;
    for(int i = 0; i < n; i++)
    {
        if(arr[i]&1)
        {
            a = a^arr[i];
        }
    }
    ans.push_back(a);
    b = a ^ uniq;
    ans.push_back(b);

    return ans;
}

int findDuplicate1(int arr[], int n)
{
    int dupl = 0;
    for(int i = 0; i < n; i++)
    {
        dupl = dupl ^ arr[i];
    }
    for(int i= 1; i < n; i++)
    {
        dupl = dupl^i;
    }
    return dupl;
}

bool isValid(string str){
        stack<char> st;

        for(int i = 0; i < str.length(); ++i){
            if(str[i] == '('){
                st.push(str[i]);
            }else{
                if(st.empty()) return false;
                st.pop();
            }
        }

        if(st.empty()) return true;
        return false;
    }


    // int arr1[9] = {4, 4, 2, 4, 4, 5, 5, 9, 9};
    
    // int uniq = findUnique1(arr1, 9);
    // cout << " unique -> "<< uniq << endl;

    // int arr2[9] = {1, 2, 3, 4, 5, 6, 7, 8, 8};
    // int dupl = findDuplicate1(arr2, 9);
    // cout << " dupl -> "<< dupl << endl;   // wrong

    // int arr3[8] = {1, 1, 2, 3, 4, 4, 5, 5};
    // vector<int> uniques = find2Uniques(arr3, 8);
    // printVector(uniques);

    // string str = "(()())";
    // cout << isValid(str);

int reduceToOneDigit(int num) {
    while (num > 9) {
        int sum = 0;

        // Add the digits of the number
        while (num > 0) {
            sum += num % 10;
            num /= 10;
        }

        num = sum;
    }

    return num;
}

int main() {
    // Read input
    string comp;
    cin >> comp;

    int equPoint;
    cin >> equPoint;

    int valency1 = -1, valency2 = -1;

    int ch1 = static_cast<int>(comp[0]);
    int ch2 = static_cast<int>(comp[1]);

    valency1 = reduceToOneDigit(ch1);
    valency2 = reduceToOneDigit(ch2);

    // if any valency is 0 return false not possible bro
    if (valency1 == 0 || valency2 == 0) {
        cout << "Not Possible" << endl;
        return 0;
    }

    // cout << valency1 <<" "<<valency2;
    vector<pair<int, int>> combinations;

    for (int i = equPoint / valency1; i >= 0; i--) {
        int remaining = equPoint - i * valency1;
        // cout << remaining%valency2 << " ";
        if (remaining % valency2 == 0) {
            int j = remaining / valency2;
            if(i!= 0 && j!= 0){

            combinations.push_back({i, j});
            }
        }
    }
   
    sort(combinations.rbegin(), combinations.rend());

    for (const auto& comb : combinations) {
        cout << comp[0] << comb.first << " " << comp[1] << comb.second << endl;
    }

    if(combinations.size() == 0){
        cout << "Not Possible" << endl;
        return 0;
    }

    return 0;
}