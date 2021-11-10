#include <iostream>
using namespace std;

bool helper(int* arr, int n, int start, int lsum, int rsum)
{
 
	if (start == n)
        return lsum == rsum;
 
    if (arr[start] % 5 == 0)
        lsum += arr[start];
 	
    else if (arr[start] % 3 == 0)
        rsum += arr[start];
 	
    else
 		return helper(arr, n, start + 1, lsum + arr[start], rsum)
           || helper(arr, n, start + 1, lsum, rsum + arr[start]);
    
    return helper(arr, n, start + 1, lsum, rsum);
}
bool splitArray(int *input, int size) {
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input and printing output is handled automatically.
     */
 return helper(input,size,0,0,0);   
}

int main() {

	int size;
	cin>>size;
	int *input=new int[1+size];	
	
	for(int i=0;i<size;i++)
		cin>>input[i];
	
    if(splitArray(input, size)) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }

	
	return 0;

}
