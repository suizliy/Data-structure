#include <iostream>

using namespace std;
struct Node {
    int value = 0;
    Node *next ;
};
 Node *head = NULL;
//insert function
void insertNode(int data) {
    Node *newNode;
    Node *Last ;
    newNode = new Node;
    newNode->value = data;

    if (head == NULL) {
        head = newNode;
        newNode->next = NULL;
    }
    else {
        Last = head;
        while (Last->next != NULL) {
            Last = Last->next;
        }
        Last->next = newNode;
        newNode->next = NULL;
    }
}
void display(){
        Node *currentNode = head;
        if(head == NULL ) {
            cout<<"empty"<<endl;
        }
        else {
            currentNode = head;
            while(currentNode != NULL) {
               cout<<currentNode->value<<" ";
                currentNode = currentNode->next;

            }

        }

    }




int main() {
    cout<<" linked list "<<" ";
    display();
    return 0;
}
