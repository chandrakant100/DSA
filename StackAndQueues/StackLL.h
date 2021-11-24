#include <iostream>
using namespace std;

class Node {
   public:
    int data;
    Node *next;

    Node(int data) {
        this->data = data;
        next = NULL;
    }
};
class Stack {
	// Define the data members
    private:
    	Node *head;
    	int counter;
    public:
    Stack() {
        // Implement the Constructor
        counter = 0;
        head = NULL;
    }

	/*----------------- Public Functions of Stack -----------------*/

    int getSize() {
        // Implement the getSize() function
    	return counter;
    }

    bool isEmpty() {
        // Implement the isEmpty() function
        return getSize() == 0;
    }

    void push(int element) {
        // Implement the push() function
    	Node *val = new Node(element);
        
        val->next = head;
        head = val;
        
        counter ++;
    }
    int pop() {
        // Implement the pop() function
        if (head == NULL)
            return -1;
        Node *temp = head;
        head = head->next;
      	temp->next = NULL;
        int val = temp->data;
        delete temp;
        counter--;
        return val;
    }

    int top() {
        // Implement the top() function
        if(head == NULL) {
			return -1;		
		}
        return head->data;
    }
};

