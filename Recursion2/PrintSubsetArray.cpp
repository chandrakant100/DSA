#include <iostream>
using namespace std;

void printSubsetsOfArray(int input[],int size,int *output,int m)
{
    if (size == 0)
    {
        for (int i{0}; i<m; i++)
        {
            cout<<output[i]<<" ";
        }
        cout<<endl;
        return;
    }
    printSubsetsOfArray(input+1,size-1,output,m);
    
    int *temp = new int[m+1];
    int i{0};
    for (; i<m; i++)
    {
        temp[i] = output[i];
    }
    temp[i] = input[0];
    printSubsetsOfArray(input+1,size-1,temp,m+1);
    
}
void printSubsetsOfArray(int input[], int size) {
	// Write your code here
    int *output = new int[10];
    printSubsetsOfArray(input,size,output,0);
}

int main() {
  int input[1000],length;
  cin >> length;
  for(int i=0; i < length; i++)
  	cin >> input[i];
  printSubsetsOfArray(input, length);
}
