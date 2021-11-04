#include <iostream>
#include <bits/stdc++.h>
using namespace std;


void printSubsetSumToK(int input[],int size,int k,vector<int> v)
{
    if (k == 0)
    {
        for (int i = v.size() - 1; i >= 1;i--)
        {
            cout<<v.at(i)<<" ";
        }
        cout<<endl;
        return;
    }
    if (size == 0)
        return;
    
    printSubsetSumToK(input,size-1,k,v);
    
    v.push_back(input[size-1]);
    
    printSubsetSumToK(input,size-1,k-input[size-1],v);
}
void printSubsetSumToK(int input[], int size, int k) {
    // Write your code here
    vector<int> v{0};
	printSubsetSumToK(input,size,k,v);
}

int main() {
  int input[1000],length,k;
  cin >> length;
  for(int i=0; i < length; i++)
    cin >> input[i];
  cin>>k;
  printSubsetSumToK(input, length,k);
}
