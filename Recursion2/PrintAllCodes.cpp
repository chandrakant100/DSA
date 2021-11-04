#include <iostream>
#include <string.h>
using namespace std;

void printAllPossibleCodes(string input,string out)
{
    if (input.length() == 0)
    {
        for (int i{0}; i < out.length(); i++)
        	cout<<out[i];
        cout<<endl;
        return;
    }
    
    char ch = (input[0]-48)+96;
    
    if (input[0] == '0')
        return;
    printAllPossibleCodes(input.substr(1),out+ch);
    
    if (input.length() > 1)
    {
        int d = (input[0] - 48)*10 +(input[1]-48);
        
        if (d>26)
            return;
    	char ch2 = d+96;
        printAllPossibleCodes(input.substr(2),out+ch2);
    }
 
}
void printAllPossibleCodes(string input) {
    /*
    Given the input as a string, print all its possible combinations. You do not need to return anything.
    */
    
    string out = "";
    
    printAllPossibleCodes(input,out);
}


int main(){
    string input;
    cin >> input;

    printAllPossibleCodes(input);
    return 0;
}
