#include <iostream>
using namespace std;

long staircase(int n)
{
	//Write your code here                                                                                                                                
	long res[n + 1];
    res[0] = 1;
    res[1] = 1;
    res[2] = 2;
    for (int i = 3; i <= n; i++)
        res[i] = res[i - 1] + res[i - 2] + res[i - 3];
 
    return res[n];
}
int main()
{
	int n;
	cin >> n;
	cout << staircase(n);
}