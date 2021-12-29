#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int kthLargest(int* arr, int n, int k) {
    // Write your code here
	priority_queue<int, vector<int>, greater<int> > pq;
    
    for (int i{0}; i<k; i++)
        pq.push(arr[i]);
    
    for (int i{k}; i<n; i++)
    {
        if (arr[i] > pq.top())
        {
            pq.pop();
            pq.push(arr[i]);
        }
    }
    int temp{k};
    while(temp == 1)
    {
        pq.pop();
        temp--;
    }
    return pq.top();
}
int main() {
    int n;
    cin >> n;

    int* arr = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int k;
    cin >> k;

    cout << kthLargest(arr, n, k);

    delete[] arr;
}