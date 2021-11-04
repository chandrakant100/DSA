#include <iostream>
#include <string>
using namespace std;

int returnPermutations(string input, string output[]){
   	/* Don't write main() function.
	 * Don't read input, it is passed as function argument.
	 * Print output as specified in the question
	*/
	if (input.length() == 0)
    {
        output[0] = "";
        return 1;
    }
    int check{0};
    for (int i{0}; i<input.length(); i++)
    {
        string temp[1000];
    	int size = returnPermutations(input.substr(0,i) + input.substr(i+1),temp);
        
        for (int j{0}; j < size; j++)
        {
            output[check] = input[i]+temp[j];
            check ++;
        }

    }
    return check; 
}

int main(){
    string input;
    cin >> input;
    string output[10000];
    int count = returnPermutations(input, output);
    for(int i = 0; i < count && i < 10000; i++){
        cout << output[i] << endl;
    }
    return 0;
}
