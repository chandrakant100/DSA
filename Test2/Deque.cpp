#include<iostream>
using namespace std;

// Driver program to test above function
class Node {
    public:
    int data;
    Node *front;
    Node *rear;
    
    Node (int data)
    {
        this->data = data;
        front = NULL;
        rear = NULL;
    }
};
class Deque {
    // Complete this class
	public:
    Node *head;
    Node *tail;
    int size;
    int count;
    
    Deque(int size)
    {
        head = nullptr;
        tail = NULL;
        this->size = size;
        count = 0;
    }
    void insertFront(int val)
    {
        if (count >= size)
        {
            cout<<"-1"<<endl;
            return;
        }
        count ++;
        Node *info = new Node(val);
        if (head == nullptr)
        {
            head = info;
            tail = info;
            return;
        }
        
        info->rear = head;
        head->front = info;
        head = info;
        
    }
    void insertRear(int val)
    {
        if (count >= size)
        {
            cout<<"-1"<<endl;
            return;
        }
        count ++;
        Node *info = new Node(val);
        if (tail == nullptr)
        {
            head = tail = info;
            return;
        }
        
        info->front = tail;
        tail->rear = info;
        tail = info;
    }
    void deleteFront()
    {
        if (head == nullptr)
        {
            cout<<"-1"<<endl;
            return;
        }
        Node *temp = head;
        head = head->rear;
        if (!head)
        {
            tail = nullptr;
        }
        else
        {
        	head->front = nullptr;
        }
        
        delete temp;
        count --;
    }
    void deleteRear()
    {
        if (tail == nullptr)
        {
            cout<<"-1"<<endl;
            return;
        }
        Node *temp = tail;
        tail = tail->front;
        if (tail == nullptr)
        {
            head = nullptr;
        }
        else
        {
        	tail->rear = nullptr;
        }
        delete temp;
        count --;
    }
    int getFront()
    {
        if (head == nullptr)
            return -1;
        return head->data;
    }
    int getRear()
    {
        if (tail == nullptr)
            return -1;
        return tail->data;
    }
};
int main()
{
    Deque dq(10);
    int choice,input;
    while(true) {
        cin >> choice;
        switch (choice) {
            case 1:
                cin >> input;
                dq.insertFront(input);
                break;
            case 2:
                cin >> input;
                dq.insertRear(input);
                break;
            case 3:
                dq.deleteFront();
                break;
            case 4:
                dq.deleteRear();
                break;
            case 5:
                cout << dq.getFront() << "\n";
                break;
            case 6:
                cout << dq.getRear() << "\n";
                break;
            default:
                return 0;
        }
    }
    
    return 0;
}