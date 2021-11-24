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
int checkLength(Node *head)
{
    int count{0};
    while(head != NULL)
    {
        count++;
        head = head->next;
    }
    return count;
}
Node *appendLastNToFirst(Node *head, int n)
{
    //Write your code here
  	int length = checkLength(head);
    int toMove = length - n;
    
    if (toMove <= 0 || toMove == length)
    {
        return head;
    }
    Node *newhead = head;
    Node *buff = NULL;
    while(toMove != 0)
    {
        if (toMove == 1)
        {
            buff = newhead;
        }
        newhead = newhead->next;
        toMove--;
    }
    
    Node *temp = newhead;
    while(temp->next != NULL)
    {
        temp = temp->next;
    }
    
    temp->next = head;
    buff->next = NULL;
    head = newhead;
    
    return head;
}
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		Node *head = takeinput();
		int n;
		cin >> n;
		head = appendLastNToFirst(head, n);
		print(head);
	}
	return 0;
}