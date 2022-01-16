#include <bits/stdc++.h>
using namespace std;

int countWays(const vector<int>& a, int k, int index) {
	if(index == a.size()) {
		return k == 0;
	}

	int count = 0;
	if(k - a[index] >= 0) {
		count += countWays(a, k - a[index], index+1);
	}
	count += countWays(a, k, index+1);
	return count;
}

int main()
{
	int t; 
    cin >> t;
	while(t--)
	{	
		int n, k;
		cin >> n >> k;

		vector<int> a(n);
		for(int i = 0 ; i < n ; ++i) {
			cin >> a[i];
		}

		cout << countWays(a, k, 0) << '\n';
	}
	return 0;
}

