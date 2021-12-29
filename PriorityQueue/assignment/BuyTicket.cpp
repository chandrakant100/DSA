#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int buyTicket(int *arr, int n, int k) {
    // Write your code here
    int time{0};
    
    queue<int> q;
    priority_queue<int> pq;
    
    for (int i{0}; i<n; i++)
    {
        pq.push(arr[i]);
        q.push(i);
    }
    while(1)
    {
        if (arr[q.front()] != pq.top())
        {
            q.push(q.front());
            q.pop();
        }
        else if (arr[q.front()] == pq.top() && q.front() == k)
        {
            time++;
            break;
        }
        else
        {
            time++;
            pq.pop();
            q.pop();
        }
    }
    return time;
}
int main() {
    int n;
    cin >> n;

    int *arr = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int k;
    cin >> k;

    cout << buyTicket(arr, n, k);

    delete[] arr;
}