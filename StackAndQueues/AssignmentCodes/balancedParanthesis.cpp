#include <iostream>
#include <string>
#include <stack>

using namespace std;

bool isBalanced(string expression) 
{
    // Write your code here
    int size = expression.size();
    
    stack<char> obj;
    
    for (int i{0}; i < size; i++)
    {
        if (expression[i] == '{' || expression[i] == '(' || expression[i] == '[')
        {    
            obj.push(expression[i]);
            continue;
        }
        if (expression[i] == '}')
        {
            if (obj.empty())
                return false;
            else
            {
                if (obj.top() == '{' )
                	obj.pop();
                else
                    return false;
            }
        }
        else if (expression[i] == ')')
        {
            if (obj.empty())
                return false;
            else
            {
                if (obj.top() == '(' )
                	obj.pop();
                else
                    return false;
            }
        }
        else if (expression[i] == ']')
        {
            if (obj.empty())
                return false;
            else
            {
                if (obj.top() == '[' )
                	obj.pop();
                else
                    return false;
            }
        }
    }
    if (obj.empty())
        return true;
    
	return false;
}
int main() 
{
    string input;
    cin >> input;
    cout << ((isBalanced(input)) ? "true" : "false");
}