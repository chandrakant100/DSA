#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class element
{
    public:
    int data;
    int arrayIndex;
    int position;
};
bool operator<(const element& e1, const element& e2) {return e1.data > e2.data;}

vector<int> mergeKSortedArrays(vector<vector<int>*> input) {
    // Write your code here
    priority_queue<element> pq;
    vector<int> vec;
    for (int j{0}; j<input.size(); j++)
    {
        element obj;
        obj.data = input.at(j)->at(0);
        obj.arrayIndex = j;
        obj.position = 0;

        pq.push(obj);
    }
    while(1)
    {
        if (pq.empty())
            break;
        
    	vec.push_back(pq.top().data);
        
        int arrayIndex = pq.top().arrayIndex;
        int position = pq.top().position;
        
        if (position+1 < input[arrayIndex]->size())
        {
            element obj;
            obj.data = input.at(arrayIndex)->at(position+1);
            obj.arrayIndex = arrayIndex;
            obj.position = position + 1;
            pq.push(obj);
        }
        pq.pop();   
    }
    return vec;
}    
int main() {
    int k;
    cin >> k;

    vector<vector<int> *> input;

    for (int j = 1; j <= k; j++) {
        int size;
        cin >> size;
        vector<int> *current = new vector<int>;

        for (int i = 0; i < size; i++) {
            int a;
            cin >> a;
            current->push_back(a);
        }

        input.push_back(current);
    }

    vector<int> output = mergeKSortedArrays(input);

    for (int i = 0; i < output.size(); i++) {
        cout << output[i] << " ";
    }

    return 0;
}