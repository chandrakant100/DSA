#include <iostream>
#include <bits/stdc++.h>

using namespace std;
// Change in the given string itself. So no need to return or print the changed string.

void pairStar(char input[]) {
    // Write your code here
	int len = strlen(input);
    
    if (len == 0)
        return ;
    
    if (len == 1)
        return ;
    
    if (input[0] == input[1])
    {
        int i{};
        for (i = len-1; i > 0; i--)
        {
            input[i+1] = input[i]; 
        }
        input[i+1] = '*';
        input[len+1] = '\0';
    }
    
    return pairStar(input+1);        
}
int main() {
   char input[100];
   cin.getline(input, 100);
   pairStar(input);
   cout << input << endl;
}
