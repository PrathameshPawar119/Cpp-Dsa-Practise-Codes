#include<iostream>
using namespace std;

class Nstack{
    int* arr;
    int* top;
    int* next;
    int n, s, freespot;

    public: 
    Nstack(int n, int s){
        this->n = n;
        this->s = s;
        this->freespot = 0;

        arr = new int[s];
        top = new int[n];
        next = new int[s];

        for(int i = 0; i < n; ++i){
            top[i] = -1;
        }
        for(int i = 0; i < s-1; ++i){
            next[i] = i+1;
        }

        next[s-1] = -1;
    }

    bool push(int x, int m){
        if(freespot == -1){
            return false; // stack overflow
        }

        // get index and update freeshopt
        int index = freespot;
        freespot = next[index];

        // update next
        next[index] = top[m-1];

        // insert
        arr[index] = x;

        // update top
        top[m-1] = index;

        return true;
    }

    int pop(int m){
        if(top[m-1] == -1){
            return -1; // stack under flow
        }

        int index = top[m-1];

        top[m-1] == next[index];

        next[index] = freespot;

        freespot = index;

        return arr[index];
    }

    int topElem(int m){
        if(top[m-1] == -1){
            return -1; // stack under flow
        }
        return arr[top[m-1]];
    }
};


int main(){
    Nstack* nst = new Nstack(4, 10);
    nst->push(10, 1);
    nst->push(10, 3);
    nst->push(20, 4);
    nst->pop(1);
    nst->push(23, 2);
    nst->pop(4);

    cout << nst->topElem(2)<<endl;
    cout << nst->topElem(1)<<endl;
    cout << nst->topElem(3)<<endl;
}