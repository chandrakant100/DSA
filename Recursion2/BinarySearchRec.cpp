#include <iostream>
using namespace std;

int binarySearch(int input[],int beg,int end,int element)
{
    if (end > beg)
    {
        int mid = beg + (end-beg)/2;
        if (input[mid] == element)
            return mid;
    	if (element > input[mid])
        {
            return binarySearch(input,mid+1,end,element);
        }
        else
        {
            return binarySearch(input,beg,mid-1,element);
        }
    }
    return -1;
}
int binarySearch(int input[], int size, int element) {
    // Write your code here
 	int ans = binarySearch(input,0,size,element);
    return ans;
}

int main() {
    int input[100000],length,element, ans;
    cin >> length;
    for(int i =0;i<length;i++)
    { 
        cin >> input[i];;
    }

    cin>>element;
    ans = binarySearch(input, length, element);
    cout<< ans << endl;
}
