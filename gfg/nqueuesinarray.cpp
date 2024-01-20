#include<bits/stdc++.h>
using namespace std;


class NQueue{
    int* arr;
    int* next;
    int* front;
    int* back;

    int n, s, freespot;

    NQueue(int n, int s){
        this->n = n;
        this->s = s;
        arr = new int [s];
        front = new int[n];
        back = new int[n];
        next = new int[s];

        for(int i = 0; i < n; ++i){
            front[i] = -1;
            back[i] = -1;
        }
        for(int i = 0; i < s-1; ++i){
            next[i] = i+1;
        }
        next[s-1] = -1;

        freespot = 0;
    }


    

};