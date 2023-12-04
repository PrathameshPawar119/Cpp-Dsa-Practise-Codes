#include<iostream>
using namespace std;

class CircularQueue{
    int* arr;
    int qfront;
    int qrear;

    public:
    int size;

    CircularQueue(int size){
        this->size = size;
        arr = new int[size];
        qfront = -1;
        qrear = -1;
    }

    void enqueue(int data){
        if((qfront == 0 && qrear == size-1) || qrear == (qfront-1)%size-1){
            // if size is full  || qrear is just back of qfront
            cout << "Queue is Full "<<endl;
            return;
        }
        else if(qfront == -1){
            // first element
            qfront = 0;
            qrear = 0;
        }
        else if(qrear == size-1 && qfront != 0){
            //  when qrear reached the end and qfront is in middle of array
            // continue the cycle
            qrear = 0;
        }else{
            qrear++;
        }

        arr[qrear] = data;
    }

    int dequeue(){
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
        else if(qfront == size-1){
            // qfront was at the last so continue cycle
            qfront = 0;
        }else{
            qfront++;
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

    bool isEmpty(){
        return qfront == -1;
    }

};


int main(){
 // Array vala queue

    CircularQueue* q1 = new CircularQueue(8);
    cout << "Queue is Empty ? " << q1->isEmpty();
    cout << endl;

    q1->enqueue(10);
    q1->enqueue(20);
    q1->enqueue(13);
    q1->enqueue(19);
    q1->enqueue(910);
    q1->enqueue(110);
    q1->enqueue(113);
    q1->enqueue(119);

    
    cout << "queue size " << q1->size << endl;

    cout << "qfront "<< q1->front() << endl;

    q1->dequeue();
    q1->dequeue();
    q1->dequeue();
    q1->dequeue();
    q1->dequeue();
    
    q1->enqueue(11110);
    q1->enqueue(11113);
    q1->enqueue(11119);

    cout << "qfront "<< q1->front() << endl;

}