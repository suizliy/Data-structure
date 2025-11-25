//using linked list to implement queue
// complexity of push and pop is O(1)
#include<iostream>
using namespace std;

template <class T>
class QueueLinkedList {
private:
    struct Node {
        T value;
        Node* next;
    };

    Node *front;
    Node *rear;

public:
    QueueLinkedList() {
        front = nullptr;
        rear = front;
    }

    bool isEmpty() {
        return front == nullptr;
    }

    void inqueue(T element) {
        Node *newNode = new Node;
        newNode->value = element;
        newNode->next = nullptr;

        if (isEmpty()) 
        {
            front = newNode;
            rear = front;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    void pop() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return;
        }
        if(front == rear)
        {
            delete front;
            rear = nullptr;
            front = nullptr;
        }
        else {
            Node* temp = front;  // Changed from 'auto' to 'Node*'
            front = front->next;
            delete temp;
        }
    }

    T Front() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return T();
        }
        return front->value;
    }

    T Back() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return T();
        }
        return rear->value;
    }

    ~QueueLinkedList() {
        while (!isEmpty()) {
            pop();
        }
    }
};  

int main() {
    QueueLinkedList<int> queue;
    queue.inqueue(10);
    queue.inqueue(20);
    cout << "Front element: " << queue.Front() << endl; // Output: 10
    cout << "Back element: " << queue.Back() << endl;   // Output: 20
    queue.pop();
    cout << "Front element after pop: " << queue.Front() << endl; // Output: 20

    return 0;
}
