#include <bits/stdc++.h>
using namespace std;

int fibbo(int n)
{
	//Write your code here
    int *arr = new int[n+1];
    arr[0] = 0;
    arr[1] = 1;
    arr[2] = 1;
    for (int i{3}; i<=n; i++)
    {
        arr[i] = arr[i-1]+arr[i-2];
    }
    int temp = arr[n];
    delete [] arr;

    return temp;
}
int main()
{
	int n;
	cin >> n;
	cout << fibbo(n);
}