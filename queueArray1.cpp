#include <iostream>
using namespace std;

//first in first out 
//INQUE = push , deque , is full , is empty , back , first 
//using one pointer pop() is O(n) time complexity , push() is O(1) time complexity
template <class T>
class QueueArray{
    private:
    T*Data ;
    int saize;
    int first;

    bool isFull() {
        return first == saize - 1;
    }
    public:
    QueueArray(int s = 10) {
        size = s;
        Data = new T[size];
        first = -1;
    }

    bool isEmpty(){
        return first == -1;
    }
    void inqueue(T element){
        if(isFull()){
            T *temp = new T[size * 2];
            for (int i=0; i < size; i++){
                temp[i]= Data[i];
            }
            size*=2;
            delete [] Data;
            Data = temp;
    }
        Data[++first] = element;
}
    void pop(){
        if(!isEmpty()){
            throw runtime_error("Queue is empty");
    }
    //shift elements
    for (int i=1; i < first; i++){
        Data[i-1] = Data[i]; 
    }
    first--;
}
    T Front(){
        if(isEmpty()){
            throw runtime_error("Queue is empty");
        }
        return Data[0];

    }
    T Back(){
        if(isEmpty()){
            throw runtime_error("Queue is empty");
        }
        return Data[first];
    }
    QueueArray(){
        delete[]Data;
    }


};
int main(){
    QueueArray<int>a;
    a.inqueue(10);
    a.inqueue(20);
    a.inqueue(30);
    cout<<a.Front()<<endl; //10
    
}