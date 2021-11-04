#include <iostream>
using namespace std;

// Change in the given string itself. So no need to return or print anything

void replacePi(char input[]) {
	// Write your code here
	if (*input == '\0')
        return;
    
   if(input[0] == 'p' && input[1] == 'i')
   {
       int len{0};
       for (int i{0}; input[i] != '\0'; i++)
       {
          len += 1;
       }
       	for (int i{len-1}; i >=0; i --)
        {
            input[i+2] = input[i];
        }
       input[0] = '3';
       input[1] = '.';
       input[2] = '1';
       input[3] = '4';
	}
    return replacePi(input+1);
}



int main() {
    char input[10000];
    cin.getline(input, 10000);
    replacePi(input);
    cout << input << endl;
}
