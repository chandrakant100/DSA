#include <iostream>
#include <bits/stdc++.h>
#include <math.h>

using namespace std;
int stringToNumber(char input[]) {
    // Write your code here
	int len = strlen(input);

    if (len == 1)
        return input[0] - '0';
    int val = stringToNumber(input+1);
    
    return pow(10,len-1) * (input[0] - '0') + val;
}

int main() {
    char input[50];
    cin >> input;
    cout << stringToNumber(input) << endl;
}
