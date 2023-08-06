#include <iostream>
#include <vector>
using namespace std;

void printVector(vector <string> vec){
    int size = vec.size();
    cout << "Printing vector -->" <<endl;
    for(int i=0; i < size; i++)
    {
        cout<< vec[i] << " ";
    }
    cout <<endl<< "-----" << endl;
}

void possibleKeyLetters(string nums, int index, string output, vector<string>& ans, string mapping[])
{
    // base case
    if(index == nums.size())
    {
        ans.push_back(output);
        return;
    }

    // get int from string
    int elem = nums[index] - '0';
    // cout << mapping[elem];
    string map = mapping[elem];
    for(int i = 0; i < map.length(); i++)
    {
        output.push_back(map[i]);
        possibleKeyLetters(nums, index+1, output, ans, mapping);
        output.pop_back();
    }
}


int main()
{
    string nums = "233";
    string mapping[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> ans;
    string output = "";
    int index = 0;
    possibleKeyLetters(nums, index, output, ans, mapping);

    printVector(ans);

}