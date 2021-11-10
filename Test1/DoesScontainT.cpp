#include<iostream>
#include <bits/stdc++.h>
using namespace std;


bool checksequenece(char large[] , char*small) {

    if (strlen(small) == 0)
        return true;
    if (strlen(small) != 0 && strlen(large) == 0)
        return false;
    
    bool check{false};
    if (large[0] == small[0])
    {
        check = checksequenece(large+1,small+1);
    }
    else
    {
        check = checksequenece(large+1,small);
    }
    
    return check;
}
 
int main()
{
	char large[10000];
	char small[10000];
	cin>>large;
	cin>>small;
	bool x=checksequenece(large , small);

	if(x)
		cout<<"true";
	else
		cout<<"false";

}
