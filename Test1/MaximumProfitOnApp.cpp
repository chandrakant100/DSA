#include <iostream>
#include <bits/stdc++.h>
using namespace std;


int maximumProfit(int budget[], int n) {
    // Write your code here
sort(budget,budget+n);

    int j{n-1};
    int max = budget[0]*n;

    for (int i{1}; i < n; i++)
    {
        if (max < budget[i]*j)
        {
            max = budget[i]*j;
        }
        j--;
    }    
    return max;
}

int main() {
    int n ,*input,i,*cost;
    cin>>n;
    input = new int[n];
    for(i = 0;i < n;i++)
        cin>>input[i];
    
    cout << maximumProfit(input, n) << endl;
    
}
