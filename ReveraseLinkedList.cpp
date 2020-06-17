#include <iostream>
using namespace std;

typedef struct node {
    int data;
    struct node* link;
}Node;

Node* createNode(const int& data) {
    Node* temp = new Node;
    temp->link = nullptr;
    temp->data = data;
    return temp;
}

Node* buildLinkedList(Node* head, Node* last) {
    int arr[] = {0, 1, 2, 3, 4, 5, 11, 12};
    for(const auto& data : arr) {
        if(!head) {
            last = head = createNode(data);
        }
        else {
            last->link = createNode(data);
            last = last->link;
        }
    }
    return head;
}

void print(Node* head) {
    while(head) {
        cout<<head->data<<" ";
        head = head->link;
    }
    cout<<"\n";
}

Node* reverseLinkedList(Node* head) {
    if(!head) {
        return head;
    }
    Node* previous = nullptr;
    Node* current = head;
    Node* next = head->link;

    while(next) {
        current->link = previous;
        previous = current;
        current = next;
        next = next->link;
    }
    current->link = previous;
    return current;
}

int main() {
    Node* head = nullptr;
    Node* last = nullptr;
    head = buildLinkedList(head, last);
    cout<<"\nPrinting LinkedList\n";
    print(head);
    cout<<"\n-----------------------\n";
    Node* rhead = reverseLinkedList(head);
    cout<<"\nPrinting reversed LinkedList\n";
    print(rhead);
    cout<<"\n-----------------------\n";
    return 0;
}
