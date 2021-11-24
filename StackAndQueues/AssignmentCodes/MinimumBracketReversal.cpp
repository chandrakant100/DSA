#include <iostream>
#include <string>
#include <stack>

using namespace std;

int countBracketReversals(string input) {
	// Write your code here
    if (input.size() % 2 != 0)
        return -1;
    int size = input.size();
    int count = 0;
    
    stack<char> obj;
    
    for (auto i:input)
    {
        if (i == '{')
            obj.push(i);
    	else
        {
        	if(obj.empty())
            	obj.push(i);
        	else if (!obj.empty() && obj.top() == '{')
            	obj.pop();
        
        	else if (!obj.empty() && obj.top() == '}')
            	obj.push(i);
        }
            
    }
    while(!obj.empty())
    {
        char val1 = obj.top();
        obj.pop();
        char val2 = obj.top();
        obj.pop();
        
        if (val1 == val2)
            count += 1;
        else
            count += 2;
    }
    return count;
}
int main() {
    string input;
    cin >> input;
    cout << countBracketReversals(input);
}