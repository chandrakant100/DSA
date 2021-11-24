#include <iostream>
#include <queue>

using namespace std;

void reverseQueue(queue<int> &input) {
	// Write your code here
    if (input.empty())
        return;
    
    int val = input.front();
    
    input.pop();
    reverseQueue(input);
    
    input.push(val);
}
int main() {
    int t;
    cin >> t;

    while (t--) {
        queue<int> q;
        int size;
        cin >> size;

        for (int i = 0, val; i < size; i++) {
            cin >> val;
            q.push(val);
        }

        reverseQueue(q);
        while (!q.empty()) {
            cout << q.front() << " ";
            q.pop();
        }

        cout << "\n";
    }
}