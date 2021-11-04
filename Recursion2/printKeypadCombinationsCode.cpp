#include <iostream>
#include <string>

using namespace std;
string keypad[10] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};


void printkeypad(int num,string output)
{
   if (num == 0)
   {
      cout<<output<<endl;
       return;
   }
	string store = keypad[num%10];
	for (int i{0}; i < store.size(); i++)
    {
        printkeypad(num/10,store[i]+output);
    }
}
void printKeypad(int num){
    /*
    Given an integer number print all the possible combinations of the keypad. You do not need to return anything just print them.
    */
    string output = "";
    printkeypad(num,output);
}

int main(){
    int num;
    cin >> num;

    printKeypad(num);

    return 0;
}
