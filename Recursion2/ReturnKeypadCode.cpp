#include <iostream>
#include <string>

using namespace std;
string Table [10]= {"", "", "abc", "def", "ghi", "jkl", 
                               "mno", "pqrs", "tuv", "wxyz"}; 

int keypad(int num, string output[]){
    if(num==0)
    {
        output[0]="";
        return 1;
    }
    int rem = num %10 ;
    int small=keypad(num / 10 , output) ;
    for(int i = 1 ; i< Table[rem].size(); i++)
    {
        for(int j = 0 ; j < small ; j++)
        {
            output[i*small + j] = output[j] ;
        }
    }
    
    for(int i=0 ; i<Table[rem].size() ; i++)
    {
        for(int j = 0; j<small ; j++)
        {
            output[i*small + j] +=Table[rem][i] ;
        }
    }
    return Table[rem].size()*small;
}
int main(){
    int num;
    cin >> num;

    string output[10000];
    int count = keypad(num, output);
    for(int i = 0; i < count && i < 10000; i++){
        cout << output[i] << endl;
    }
    return 0;
}
