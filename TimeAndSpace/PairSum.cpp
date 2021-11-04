#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

int pairSum(int *arr, int n, int num)
{
	//Write your code here
	unordered_map<int, int> m;
 
    for (int i = 0; i < n; i++)
        m[arr[i]]++;
 
    int twice_count = 0;
 
    for (int i = 0; i < n; i++) {
        twice_count += m[num - arr[i]];
 	
        if (num - arr[i] == arr[i])
            twice_count--;
    }
    return twice_count / 2;
}
int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		int size;
		int x;

		cin >> size;
		int *input = new int[size];

		for (int i = 0; i < size; i++)
		{
			cin >> input[i];
		}

		cin >> x;

		cout << pairSum(input, size, x) << endl;

		delete[] input;
	}
	
	return 0;
}