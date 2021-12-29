#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// void findMedianHelper(int *arr,int pos,int n)
// {
//     if (pos == n)
//         return;
//     vector<int> vec;
//     for (int i{0}; i <=pos; i++)
//         vec.push_back(arr[i]);
    
//     sort(vec.begin(),vec.end());

//     if (pos+1 % 2 != 0)
//     {
//         int median = (pos+1)/2;
//         cout<<vec[median]<<" ";
//     }
//     else
//     {
//         int i = pos/2;
//         int median = (vec[i] + vec[i+1]) / 2;
//         cout<<median<<" ";
//     }
    
//     findMedianHelper(arr,pos+1,n);
// }
void findMedian(int *arr, int n)
{
    // Write your code here
    priority_queue<int> maxheap;
	priority_queue<int,vector<int>,greater<int> > minheap;
	
    int flag{1};
    
    for (int i{0}; i<n; i++)
    {
        if (maxheap.empty() && minheap.empty())
        {
            flag = 0;
            maxheap.push(arr[i]);
            cout<<maxheap.top()<<" ";
            continue;
        }
        
      	if (arr[i] < maxheap.top())
        {
            maxheap.push(arr[i]);
        }
        else
        {
            minheap.push(arr[i]);
        }
        
        if (maxheap.size() > minheap.size())
        {
            minheap.push(maxheap.top());
            maxheap.pop();
        }
        else if (maxheap.size() < minheap.size())
        {
            maxheap.push(minheap.top());
            minheap.pop();
        }
            
        if (flag == 0)
        {
            flag = 1;
            cout<<(maxheap.top()+minheap.top())/2<<" ";
        }
        else
        {
            flag = 0;
            if (maxheap.size() > minheap.size())
                cout<<maxheap.top()<<" ";
            else
                cout<<minheap.top()<<" ";
        }
    }
    cout<<endl;
}
int main() {
    int n;
    cin >> n;

    int* arr = new int[n];

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    findMedian(arr,n);

    delete[] arr;
}
