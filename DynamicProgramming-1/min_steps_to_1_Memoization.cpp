#include <bits/stdc++.h>
using namespace std;

int countMinStepsToOne(int n)
{
	//Write your code here
    if (n <= 1)
        return 0;
    
    int b{INT_MAX},c{INT_MAX};
    
    int a = countMinStepsToOne(n-1);
    if (n % 2 == 0)
    	b = countMinStepsToOne(n/2);
    if (n % 3 == 0)
    	c = countMinStepsToOne(n/3);
    
    return min(a,min(b,c)) +1;
}
int main()
{
	int n;
	cin >> n;
	cout << countMinStepsToOne(n);
}