#include <iostream>
using namespace std;

class Node {
   public:
    int data;
    Node *next;
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};
Node *takeinput() {
    int data;
    cin >> data;
    Node *head = NULL, *tail = NULL;
    while (data != -1) {
        Node *newnode = new Node(data);
        if (head == NULL) {
            head = newnode;
            tail = newnode;
        } else {
            tail->next = newnode;
            tail = newnode;
        }
        cin >> data;
    }
    return head;
}

void print(Node *head) {
    Node *temp = head;

    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << "\n";
}
Node *reverseLinkedList(Node *head) {
    // Write your code here
    
    if (head == NULL)
        return head;
    
    Node *temp1 = head->next;
    Node *temp2 = NULL;
    Node *tail = head;
    while(1)
    {
        if (temp1 == NULL)
            break;
        temp2 = temp1->next;
        temp1->next = head;
        head = temp1;
        temp1 = temp2;
    }
    tail->next = NULL;
    
    return head;
}
int main() {
    int t;
    cin >> t;

    while (t--) {
        Node *head = takeinput();
        head = reverseLinkedList(head);
        print(head);
    }

    return 0;
}