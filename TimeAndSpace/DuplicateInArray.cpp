#include <iostream>
using namespace std;

int findDuplicate(int *arr, int n)
{
    //Write your code here
    int count1{0},count2{0};
    
    for (int i{0}; i<=n-2; i++)
    {
        count1 += i;
    }
    for (int i{0}; i<n; i++)
    {
        count2 += arr[i];
    }
    
    return count2-count1;
}
int main()
{
	int t;
	cin >> t;
	
	while (t--)
	{
		int size;
		cin >> size;
		int *input = new int[size];

		for (int i = 0; i < size; i++)
		{
			cin >> input[i];
		}

		cout << findDuplicate(input, size) << endl;
	}

	return 0;
}