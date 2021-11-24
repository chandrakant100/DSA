#include <iostream>
#include <string>
#include <stack>

using namespace std;

bool checkRedundantBrackets(string expression) {
	// Write your code here
    int counter{0};
    stack<char> obj;
    
    for (auto val:expression)
    {
        if(val != ')')
            obj.push(val);
        else
        {
            counter = 0;
            while(obj.top() != '(')
            {
                obj.pop();
                counter ++;
            }
            if (counter == 0)
                return true;
            else
            	obj.pop();
        }
    }
    if (counter <= 1)
        return true;
    
    return false;
}
int main() {
    string input;
    cin >> input;
    cout << ((checkRedundantBrackets(input)) ? "true" : "false");
}