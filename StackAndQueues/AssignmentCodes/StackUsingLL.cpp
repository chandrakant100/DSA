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
int main() {
    Stack st;

    int q;
    cin >> q;

    while (q--) {
        int choice, input;
        cin >> choice;
        switch (choice) {
            case 1:
                cin >> input;
                st.push(input);
                break;
            case 2:
                cout << st.pop() << "\n";
                break;
            case 3:
                cout << st.top() << "\n";
                break;
            case 4:
                cout << st.getSize() << "\n";
                break;
            default:
                cout << ((st.isEmpty()) ? "true\n" : "false\n");
                break;
        }
    }
}