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

Node *skipMdeleteN(Node *head, int M, int N)
{  
    if (head == NULL)
        return head;
    
    if (M == 0)
        return NULL;
    
    Node *curr = head,*delpt,*temp;
    
    while(curr != NULL)
    {
        for (int i{0}; i<M-1 && curr!= NULL;i++)
        {
            curr = curr->next;
        }
        if (curr == NULL)
            return head;
        delpt = curr->next;
        
        for (int i{0}; i<N && delpt != NULL;i++)
        {
            temp = delpt;
            delpt = delpt->next;
            free(temp);
        }
        
        curr->next = delpt;
        curr = curr->next;
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
		int m, n;
		cin >> m >> n;
		head = skipMdeleteN(head, m, n);
		print(head);
	}
	return 0;
}