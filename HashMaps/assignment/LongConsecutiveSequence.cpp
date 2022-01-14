#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

#include <unordered_map>

vector<int> longestConsecutiveIncreasingSequence(int *arr, int n) {
    // Your Code goes here
	unordered_map<int,int> map;
    
    for (int i{0}; i<n; i++)
        map[arr[i]] = i;
    
    int maxlength{0},beg{0},last{0},count{1};
    
    for (int i{0}; i<n; i++)
    {
        int val = arr[i];
        int start = val;
        int end = val;
        while(true)
        {
            val++;
            if (map.count(val) != 0)
            {
                count++;
                end = val;
            }
            else
                break;
        }
        val = arr[i];
        while(true)
        {
            val--;
            if (map.count(val) != 0)
            {
                count++;
                start = val;
            }
            else
                break;
        }
        if (count > maxlength)
        {
            maxlength = count;
            beg = start;
            last = end;
        }
        else if (count == maxlength)
        {
            maxlength = count;
            if (map[start] < map[beg])
            {
                beg = start;
                last = end;
            }
        }
        count = 1;
    }
    vector<int> vec;
    vec.push_back(beg);
    vec.push_back(last);
    
    return vec;
}
int main() {
    int size;
    cin >> size;

    int* arr = new int[size];

    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    vector<int> ans = longestConsecutiveIncreasingSequence(arr, size);

    for (auto i = ans.begin(); i != ans.end(); ++i)
        cout << *i << " ";

    delete[] arr;
}
