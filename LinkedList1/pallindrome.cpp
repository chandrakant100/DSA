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
int checkSize(Node *head)
{
    int count{0};
    while(head != NULL)
    {
        count ++;
        head = head->next;
    }
    
    return count;
}
Node *reverse(Node *head)
{
    Node *temp = head->next;
    head->next = NULL;
    
    while(temp != NULL)
    {
        Node *buff = temp;
        temp = temp->next;
        buff->next = head;
        head = buff;
    }
    
    return head;
}
bool isPalindrome(Node *head)
{
    //Write your code here
    
    if (head == NULL || head->next == NULL)
        return true;
    int size = checkSize(head);
    
    int size1 = size/2;
    int size2 = size/2;
        
    Node *head1 = head;
    Node *tail1 = head;
    Node *head2 = NULL;
    Node *tail2 = NULL;
        
    if (size % 2 == 0)
    {
        while(size1 != 1)
        {
            tail1 = tail1->next;
            size1 --;
        }
        
    	head2 = tail1->next;
        tail2 = tail1->next;
        tail1->next = NULL;
        
        while(size2 != 1)
        {
            tail2 = tail2->next;
            size2 --;
        }
    }
    else
    {
        while(size1 != 1)
        {
            tail1 = tail1->next;
            size1 --;
        }
        
    	head2 = tail1->next->next;
        tail2 = tail1->next->next;
        tail1->next = NULL;
        
        while(size2 != 1)
        {
            tail2 = tail2->next;
            size2 --;
        }
    }
    Node *rev = reverse(head2);
    
    while(rev != NULL)
    {
    	if (head1->data != rev->data)
        {
            return false;
        }
        head1 = head1->next;
        rev = rev->next;
    }
    
    return true;
}
int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		Node *head = takeinput();
		bool ans = isPalindrome(head);

		if (ans) cout << "true";
		else cout << "false";

		cout << endl;
	}

	return 0;
}