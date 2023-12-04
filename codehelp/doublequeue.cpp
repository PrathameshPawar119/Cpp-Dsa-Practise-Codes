#include <iostream>
using namespace std;

class DoubleQueue{

    int* arr;
    int qfront;
    int qrear;

    public:

    int size;
    DoubleQueue(int size){
        this->size = size;
        arr = new int[size];
        qfront = -1;
        qrear = -1;
    }

    void push_back(int data){
        if((qfront == 0 && qrear == size-1) || qrear == (qfront-1)%(size-1)){
            cout << "Queue is Full "<<endl;
            return;
        }
        else if(qfront == -1){
            // first element
            qfront = 0;
            qrear = 0;
        }else if(qrear == size -1 && qfront != 0){
            // continue cycle
            qrear = 0;
        }else{
            qrear++;
        }

        arr[qrear] = data;
    }

    void push_front(int data){
        if((qfront == 0 && qrear == size-1) || qrear == (qfront-1)%(size-1)){
            cout << "Queue is Full "<<endl;
            return;
        }

        else if(qfront == -1){
            qfront = 0;
            qrear = 0;
        }else if(qfront == 0 && qrear != size-1){
            qfront = size-1;
        }else{
            qfront--;
        }
        arr[qfront] = data;
    }

    int pop_front(){
        if(qfront == -1){
            // queue is empty
            cout << "Queue us Empty"<<endl;
            return -1;
        }
        
        int dt = arr[qfront];
        arr[qfront] = -1;

        if(qfront == qrear){
            // only one element is left
            qfront = qrear = -1;
        }
        else if(qfront == size-1 && qrear != 0){
            // qfront was at the last so continue cycle
            qfront = 0;
        }else{
            qfront++;
        } 

        return dt;
    }

    int pop_back(){
        if(qfront == -1){
            cout << "Queue is Empty"<<endl;
            return -1;
        }
        
        int dt = arr[qrear];
        arr[qrear] = -1;

        if(qfront == qrear){
            // only one element is left
            qfront = qrear = -1;
        }
        else if(qrear == 0 && qfront != size-1){
            // qfront was at the last so continue cycle
            qrear = size-1;
        }else{
            qrear--;
        } 

        return dt;
    }

    int front(){
        if(qfront == -1){
            // queue is empty
            cout << "Queue us Empty"<<endl;
            return -1;
        }

        return arr[qfront];
    }

    int back(){
        if(qrear == -1){
            // queue is empty
            cout << "Queue us Empty"<<endl;
            return -1;
        }

        return arr[qrear];
    }

    bool isEmpty(){
        return qfront == -1;
    }

};


int main(){

    DoubleQueue* q1 = new DoubleQueue(8);
    cout << "Queue is Empty ? " << q1->isEmpty();
    cout << endl;

    q1->push_back(10);  //10
    q1->push_front(20); //20 10
    q1->push_back(13);  //20 10 13
    q1->push_front(19); // 19 20 10 13
    q1->push_back(910); //19 20 10 13 910
    q1->push_front(110); // 110 19 20 10 13 910
    q1->push_back(113); // 110 19 20 10 13 910 113
    q1->push_front(119); // 119 110 19 20 10 13 910 113

    
    cout << "queue size " << q1->size << endl;

    cout << "qfront "<< q1->front() << endl;

    cout << "popping -> " << q1->pop_back() << endl; // 119 110 19 20 10 13 910
    cout << "popping -> " << q1->pop_front() << endl; // 110 19 20 10 13 910
    cout << "popping -> " << q1->pop_back() << endl;// 110 19 20 10 13
    cout << "popping -> " << q1->pop_back() << endl;// 110 19 20 10
    cout << "popping -> " << q1->pop_front() << endl;// 19 20 10

        cout << "back "<< q1->back() << endl;

    
    q1->push_back(11110); // 19 20 10 11110
    q1->push_back(11113); // 19 20 10 11110 11113
    q1->push_front(11119); // 11119 19 20 10 11110 11113

    cout << "qfront "<< q1->front() << endl;

}