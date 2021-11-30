//delete alternate Node in a linked list
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node * next;
    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }
    
    ~Node() {
        if(next) {
            delete next;
        }
    }
};
Node* takeinput() {
    int data;
    cin >> data;
    Node *head = NULL, *tail = NULL;
    while(data != -1){
        Node *newNode = new Node(data);
        if(head == NULL) {
            head = newNode;
            tail = newNode;
        }
        else{
            tail -> next = newNode;
            tail = newNode;
        }
        cin >> data;
    }
    return head;
}

void print(Node *head) {
    Node *temp = head;
    while(temp != NULL) {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << endl;
}
void deleteAlternateNodes(Node *head) {
    //Write your code here
    if (head == nullptr || head->next == nullptr)
        return;
    
    Node *temp = head;
    
    while(temp != nullptr)
    {
        if (temp->next->next == nullptr)
            break;
        
        Node *temp2 = temp->next;
        
        temp->next = temp->next->next;
        temp = temp->next;
        temp2->next = nullptr;
        
        delete temp2;
    }
    temp->next = nullptr;
}
int main() {
    Node *head = takeinput();
    deleteAlternateNodes(head);
    print(head);
    delete head;
    return 0;
}