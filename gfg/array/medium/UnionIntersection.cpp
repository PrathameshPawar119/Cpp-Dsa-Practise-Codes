#include<iostream>
#include<unordered_set>
#include<vector>
#include "../default_funcs.cpp"
using namespace std;

void sort(vector<int>& vect)
{  // counting sort O(n)
    int min = 100000, max = -100000;
    for(int num: vect)
    {
        if(num > max)
        {
            max = num;
        }
        if(num < min)
        {
            min = num;
        }
    }

    int range = max - min+1;
    vector<int> holes[range];
    for(int i = 0; i < vect.size(); i++)
    {
        int position = vect[i] - min;
        holes[position].push_back(vect[i]);
    }

    int index = 0;
    for(int i = 0; i < range; i++)
    {
        vector<int> ::iterator it;
        for(it = holes[i].begin(); it != holes[i].end(); it++)
        {
            vect[index++] = *it;
        }
    }
}

vector<int> IntersectionTwoArray(int arr1[], int arr2[], int n1, int n2)
{
    unordered_set<int> st;
    vector <int> ans;
    for(int i = 0; i < n1; i++)
    {
        st.insert(arr1[i]);
    }

    for(int i = 0; i < n2; i++)
    {
        if(st.find(arr2[i]) != st.end())
        {
            ans.push_back(arr2[i]);
        }
    }

    return ans;
}

vector<int> Union3Arrays(int arr1[], int arr2[], int arr3[], int n1, int n2, int n3)
{
    unordered_set<int> st;

    for(int i = 0; i < n1; i++)
    {
        st.insert(arr1[i]);
    }
    for(int i = 0; i < n2; i++)
    {
        st.insert(arr2[i]);
    }
    for(int i = 0; i < n3; i++)
    {
        st.insert(arr3[i]);
    }

    vector<int> ans;
    for(int num: st)
    {
        ans.push_back(num);
    }

    return ans;
}

vector<int> Intersection3Arrays(int arr1[], int arr2[], int arr3[], int n1, int n2, int n3)
{
    unordered_set<int> s1, s2, s3;
    for(int i = 0; i < n1; i++)
    {
        s1.insert(arr1[i]);
    }
    for(int i = 0; i < n2; i++)
    {
        s2.insert(arr2[i]);
    }
    for(int i = 0; i < n3; i++)
    {
        s3.insert(arr3[i]);
    }


    vector<int> ans;
    for(int num: s1)
    {
        if((s2.find(num) != s2.end()) && (s3.find(num) != s3.end()))
        {
            ans.push_back(num);
        }
    }

    sort(ans);
    return ans;

}

int main()
{
    int arr1[4] = {1, 2, 3, 5};
    int arr2[6] = {2, 3, 6, 7, 8, 9};
    int arr3[3] = {2, 3, 10};

    vector<int> Union3Array = Union3Arrays(arr1, arr2, arr3, 4, 6, 3); 
    // time -> O(n1+n2+n3) space -> O(n1+n2+n3)  // excluding auxillary space
    vector<int> IntersectionTwoArr = IntersectionTwoArray(arr1, arr2, 4, 6);
    vector<int> Intersection3Arr = Intersection3Arrays(arr1, arr2, arr3, 4, 6, 3);
    // time -> O(n1+n2+n3+n) space -> O(n1+n2+n3)  // excluding auxillary space

    printVector(Union3Array);
    printVector(IntersectionTwoArr);
    printVector(Intersection3Arr);

}