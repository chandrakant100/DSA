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
Node *evenAfterOdd(Node *head)
{
	//write your code here
    
    if (head == NULL)
        return head;
    
    Node *head1 = NULL;
    Node *head2 = NULL;
    Node *tail1 = NULL;
    Node *tail2 = NULL;
    
    while(head != NULL)
    {
        if (head->data % 2 == 0)
        {
            Node *val = new Node(head->data);
            
            if (head1 == NULL)
            {
                head1 = val;
                tail1 = val;
            }
            else
            {
                tail1->next = val;
                tail1 = val;
            }
            
        }
        else
        {
            Node *val = new Node(head->data);
            if (head2 == NULL)
            {
                head2 = val;
                tail2 = val;
            }
            else
            {
                tail2->next = val;
                tail2 = val;
            }
        }
        
        head = head->next;
    }
    
    if (head1 == NULL)
        head = head2;
    else if (head2 == NULL)
        head = head1;
    else
    {
        tail2->next = head1;
        head = head2;
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
		head = evenAfterOdd(head);
		print(head);
	}
	return 0;
}