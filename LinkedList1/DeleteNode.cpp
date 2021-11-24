#include <iostream>
using namespace std;

class Node
{
public:
	int data;
	Node *next;
	Node(int data)
	{
		this->data = data;
		this->next = NULL;
	}
};

Node *takeinput()
{
	int data;
	cin >> data;
	Node *head = NULL, *tail = NULL;
	while (data != -1)
	{
		Node *newNode = new Node(data);
		if (head == NULL)
		{
			head = newNode;
			tail = newNode;
		}
		else
		{
			tail->next = newNode;
			tail = newNode;
		}
		cin >> data;
	}
	return head;
}

void print(Node *head)
{
	Node *temp = head;
	while (temp != NULL)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}
Node *deleteNode(Node *head, int pos)
{
    // Write your code here.
    if (head == NULL)
    {
        return NULL;
    }
    if (pos == 0)
    {
    	Node *temp = head;
        head = head->next;
        temp->next = NULL;
        
        delete temp;
        return head;
    }
    Node *temp = head;
    
    while(temp != NULL)
    {
        if (pos == 1)
        {
            if (temp->next == NULL)
                break;
            
            Node *pt = temp->next;
            temp->next = pt->next;
            
            pt->next = NULL;
            delete pt;
            break;
        }
        pos --;
        temp = temp->next;
    }
    return head;
}

int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		Node *head = takeinput();
		int pos;
		cin >> pos;
		head = deleteNode(head, pos);
		print(head);
	}

	return 0;
}