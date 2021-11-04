#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int arrayRotateCheck(int *input, int size)
{
    //Write your code here
    if (size == 1)
        return *input;
    
	int *temp = new int[size];
    int count{0};
    for (int i{0}; i<size; i++)
    {
        temp[i] = input[i];
    }
    
    sort(temp,temp+size);
    
    for (int i{0}; i < size; i++)
    {
        if (input[i] > temp[i])
            count++;
        else
            break;
    }
    delete [] temp;
    return count;
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

		cout << arrayRotateCheck(input, size) << endl;
		delete[] input;
	}
	
	return 0;
}