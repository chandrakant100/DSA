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
int checksize(Node *head)
{
    int count{0};
    
    while(head != NULL)
    {
        count ++;
        head = head->next;
    }
    
    return count;
}
Node *mergeTwoSortedLinkedLists(Node *head1, Node *head2)
{
    //Write your code here
    Node *fh = NULL;
    Node *ft = NULL;
    
    if (head1 == NULL && head2 != NULL)
        return head2;
    else if (head1 != NULL && head2 == NULL)
        return head1;
    else if (head1 == NULL && head2 == NULL)
        return NULL;
    
    while (1)
    {
        if (head1 == NULL || head2 == NULL)
            break;
        
        if (fh == NULL && ft == NULL)
        {
            if (head1->data < head2->data)
            {
                fh = head1;
                ft = head1;
                head1 = head1->next;
            }
            else
            {
                fh = head2;
                ft = head2;
                head2 = head2->next;
            }
        }
        else
        {
            if (head1->data < head2->data)
            {
                ft->next = head1;
                ft = head1;
                head1 = head1->next;
            }
            else
            {
                ft->next = head2;
                ft = head2;
                head2 = head2->next;
            }
        }
    }
    if (head1 == NULL)
    {
        ft->next = head2;
    }
    else
        ft->next = head1;
    
    return fh;
}
Node *mergeSort(Node *head)
{
	//Write your code here
    
    int size = checksize(head);
    
    if (size == 1)
        return head;
    if (head == NULL)
        return head;
    
    int mid = (size+1) / 2;
    
    Node *head1 = head;
    Node *head2 = head;
    
    while(mid != 1)
    {
        head1 = head1->next;
        mid --;
    }
    head2 = head1->next;
    head1->next = NULL;
    head1 = head;
   
    Node *checkHead1 = mergeSort(head1);
    Node *checkHead2 = mergeSort(head2);
    
    
    Node *merge = mergeTwoSortedLinkedLists(checkHead1,checkHead2);
    
	return merge;
}
int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		Node *head = takeinput();
		head = mergeSort(head);
		print(head);
	}

	return 0;
}