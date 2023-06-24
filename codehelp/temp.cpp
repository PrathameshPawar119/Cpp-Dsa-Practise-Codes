#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n = 0;
	cin >> n;
	
	vector <string> vect;
	while(n--)
	{
	    string str;
	    cin >> str;
	    
	    vect.push_back(str);
	}
	

    for(int i = 0; i< vect.size(); i++)
    {
        
        cout << v2[i] << " ";
    }


	
	return 0;
}
