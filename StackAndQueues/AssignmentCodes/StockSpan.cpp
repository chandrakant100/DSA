#include <iostream>
#include <stack>

using namespace std;

int* stockSpan(int *price, int size)  {
	// Write your code here
    if (size == 1)
        return price;
    
	int *arr = new int[size];
    arr[0] = 1;
    
    stack<int> obj;
    obj.push(0);
    
    for (int i{1}; i<size; i++)
    {
        while(price[i] > price[obj.top()] )
        {
            obj.pop();
            if (obj.empty())
                break;
        }
        if (obj.empty())
        {
            arr[i] = i+1;
        }
        else
        {
            arr[i] = i - obj.top();
        }
        obj.push(i);
    }
    return arr;
}
int main() {
    int size;
    cin >> size;

    int *input = new int[size];
    for (int i = 0; i < size; i++) {
        cin >> input[i];
    }

    int *output = stockSpan(input, size);
    for (int i = 0; i < size; i++) {
        cout << output[i] << " ";
    }

    cout << "\n";

    delete[] input;
    delete[] output;
}