#include<iostream>
using namespace std ;

#define N 5
int Board[N][N];
int solutions = 0;

bool isSafe(int row,int col){
    int moves[4][2] = {{-2,-1},{-2,1},{-1,-2},{-1,2}};

    for(int i=0 ; i<4;i++){
        int r = row + moves[i][0];
        int c = col + moves[i][1] ;
        
        if(r >= 0 && c>=0 && c<N && Board[r][c]==1){
            return false;

        }
    }
    return true;
}


void printBoard() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cout << Board[i][j] << " ";
        cout << "\n";
    }
    cout << "\n";
}

void solve(int row, int placed){
 if(row == N ){
     if(placed == N){
        cout<<"solution"<<++solutions<<":\n";
        printBoard();

     }
     return;
 }
 
 for(int col = 0 ; col < N ;col++){
    if(isSafe(row,col)){
        Board[row][col] =1;
        solve(row+1 , placed +1);
        Board[row][col] ;
    }
 }

 solve(row+1,placed);
}

int main() {
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            Board[i][j] = 0;

    solve(0, 0);
    cout << "Total solutions found: " << solutions << "\n";
    return 0;
}