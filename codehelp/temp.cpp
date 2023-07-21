#include <iostream>
#include <vector>
using namespace std;

void printVector(vector <int> vec){
    int size = vec.size();
    cout << "Printing vector -->" <<endl;
    for(int i=0; i < size; i++)
    {
        cout<< vec[i] << " ";
    }
    cout <<endl<< "-----" << endl;
}

int maxSumWithSingleDistance(int arr[], int size)
{
    int max = 0;
    for(int i = -1; i < size/2; i++)
    {
        int sum = 0;
        for(int j = i+1; j < size; j += 2)
        {
            sum += arr[j];
        }
        if(sum > max)
        {
            cout << sum<<" ";
            max = sum;
        }
    }
    return max;

}


int main()
{
    // int arr[9] = {2, 5, 20, 10, 55, 34, 45, 25, 100};
    // cout<< "maximum--> "<< maxSumWithSingleDistance(arr, 9);
    vector<int> vec = {2, 5};

    printVector(vec);

    vec.erase(vec.begin()+0, vec.begin()+2);
    vec.insert(vec.begin()+0, 111);

    printVector(vec);
    
}