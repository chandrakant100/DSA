#include <bits/stdc++.h>
using namespace std;

int minCount(int n)
{
	//Write your code here
    if (n <= 3)
        return n;
    
	int arr[n+1];
    arr[0] = 0;
    arr[1] = 1;
    arr[2] = 2;
    arr[3] = 3;
    
    for (int i{4}; i<=n; i++)
    {
        arr[i] = i;
        
        for (int j{1}; j<=ceil(sqrt(i)); j++)
        {
            int temp = j*j;
            if (temp > i)
                break;
            else
                arr[i] = min(arr[i],1+arr[i-temp]);
        }
    }
    
    return arr[n];
}
int main()
{
	int n;
	cin >> n;
	cout << minCount(n);
}