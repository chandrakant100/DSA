#include <iostream>
using namespace std;

bool checkAB(char input[]) {
	// Write your code here
    if (input[0] == '\0')
        return true;
    bool check;
	
    if (input[0] == 'a')
    {
        if (input[1] == 'a' || input[1] == '\0')
        {
            check = true;
            return checkAB(input+1);
        }
        if (input[1] == 'b' && input[2] == 'b')
        {
            if (input[3] == '\0' || input[3] == 'a')
            {
                check = true;
                return checkAB(input+3);
            }
            else
            {
                check = false;
            }
        }
        else
        {
            check = false;
        }
    }
    return check;
}




int main() {
    char input[100];
    bool ans;
    cin >> input;
    ans=checkAB(input);
    if(ans)
        cout<< "true" << endl;
    else
        cout<< "false" << endl;
}
