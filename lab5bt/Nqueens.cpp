#include<iostream>
using namespace std ;

#define N 4

int maxflags = 0;
int board[N][N] ;


bool isSafe(int row , int col){
     for (int i = 0; i < row; i++)
        if (board[i][col] == 1) return false;

    // check upper-left diagonal
    for (int i = row-1, j = col-1; i >= 0 && j >= 0; i--, j--)
        if (board[i][j] == 1) return false;

    // check upper-right diagonal
    for (int i = row-1, j = col+1; i >= 0 && j < N; i--, j++)
        if (board[i][j] == 1) return false;

    return true;

}

void solve(int row , int count){
    if(row==N){
        if(count> maxflags) maxflags = count;
        return ;
    }

    for(int col=0 ; col<N ; col++){
        if(isSafe(row,col)){
            board[row][col] = 1;
            solve(row+1 , count+1);
            board[row][col] =0;

        }
    }
    solve(row+1,count);
}

int main() {
    // initialize matrix
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            board[i][j] = 0;

    solve(0, 0);

    cout << "Maximum flags that can be placed: " << maxflags << "\n";
    return 0;
}
