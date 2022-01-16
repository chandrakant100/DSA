/*
	Note:
	To get all the test cases accepted, make recursive calls in following order: Top, Down, Left, Right.
	This means that if the current cell is (x, y), then order of calls should be: top cell (x-1, y), 
	down cell (x+1, y), left cell (x, y-1) and right cell (x, y+1).
*/
#include<bits/stdc++.h>
using namespace std;

void ratInMazeHelper(int **arr,int **temp,int x,int y,int n)
{
    if (x == n-1 && y == n-1)
    {
        temp[x][y] = 1;
        for (int i{0}; i<n; i++)
        {
            for (int j{0}; j<n; j++)
            {
                cout<<temp[i][j]<<" ";
            }
        }
        cout<<endl;
        temp[x][y] = 0;
        return;
    }
    
    if (x<0 || x>=n || y<0 || y>=n || arr[x][y] == 0 || temp[x][y] == 1)
        return;
    
    temp[x][y] = 1;
    ratInMazeHelper(arr,temp,x-1,y,n);
    ratInMazeHelper(arr,temp,x+1,y,n);
    ratInMazeHelper(arr,temp,x,y-1,n);
    ratInMazeHelper(arr,temp,x,y+1,n);
    
    temp[x][y] = 0;
    return;
}
void ratInMaze(int **arr,int n)
{
    int **temp = new int*[n];
    
    for (int i{0}; i<n; i++)
    {
        temp[i] = new int[n];
        for (int j{0}; j<n; j++)
            temp[i][j] = 0;
    }
    ratInMazeHelper(arr,temp,0,0,n);
}
int main() {

	// Write your code here
    int n;
    cin>>n;
    int **arr = new int*[n];
    
    for (int i{0}; i<n; i++)
    {
        arr[i] = new int[n];
        for(int j{0}; j<n; j++)
            cin>>arr[i][j];
    }
    ratInMaze(arr,n);
	return 0;
}
