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
		Node *newnode = new Node(data);
		if (head == NULL)
		{
			head = newnode;
			tail = newnode;
		}
		else
		{
			tail->next = newnode;
			tail = newnode;
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
Node *swapNodes(Node *head, int i, int j)
{
	//Write your code here
    
    Node *temp1 = head;
    Node *temp2 = head;
    
    while(i != 0)
    {
        if (temp1 == NULL)
        	return head;
        temp1 = temp1->next;
        i--;
    }
    while(j != 0)
    {
        if (temp2 == NULL)
            return head;
        temp2 = temp2->next;
        j--;
    }
    
    int temp = temp1->data;
    temp1->data = temp2->data;
    temp2->data = temp;
    
    return head;
}
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int i, j;
		Node *head = takeinput();
		cin >> i;
		cin >> j;
		head = swapNodes(head, i, j);
		print(head);
	}
	return 0;
}