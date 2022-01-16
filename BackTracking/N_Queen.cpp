#include<bits/stdc++.h>
using namespace std;

int board[11][11];

bool isPossible(int n,int row,int column)
{
    // same column
    for (int i{row-1}; i>=0; i--)
    {
        if (board[i][column] == 1)
            return false;
    }
    //upper left diagonal
    for (int i{row-1},j{column-1}; i>=0 && j>=0; i--,j--)
    {
        if (board[i][j] == 1)
            return false;
    }
    // upper right daigonal
    for (int i{row-1},j{column+1}; i>=0 && j<n; i--,j++)
    {
        if (board[i][j] == 1)
            return false;
    }
    
    return true;
}
void placeNQueenHelper(int n,int row)
{
    if (row == n)
    {
        for (int i{0}; i<n; i++)
        {
            for (int j{0}; j<n; j++)
            {
                cout<<board[i][j]<<" ";
            }
        }
        cout<<endl;
        return;
    }
    for (int j{0}; j<n; j++)
    {
        if (isPossible(n,row,j))
        {
            board[row][j] = 1;
            placeNQueenHelper(n,row+1);
            board[row][j] = 0;
        }
    }
    return; 
}
void placeNQueens(int n)
{
    memset(board,0,11*11*sizeof(int));
    placeNQueenHelper(n,0);
}
int main(){
    
    // write your code here
    int x;
    cin>>x;
    placeNQueens(x);
    return 0;
}