#include <iostream>
#include <stack>

using namespace std;

int main()
{
    stack<int> obj;
    obj.push(10);
    obj.push(20);
    obj.push(30);
    obj.push(40);
    obj.push(50);

    cout<<obj.size()<<endl;

    cout<<obj.top()<<endl;
    obj.pop();
    cout<<obj.top()<<endl;
    cout<<obj.size()<<endl;

    cout<<obj.empty()<<endl;
    return 0;
}