#include<iostream>
#include<vector>

using namespace std;
int n=8;




void printboard(vector<vector<int>>board)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
    
}






bool isSafe(vector<vector<int>>board,int row,int col)
{

    for (int i = 0; i <row; i++)
    {
        if(board[i][col]==1)
        {
            return false;
        }
    }
    for (int i = row,j=col;i>=0&&j>=0;i--,j--)
    {
        if(board[i][j]==1)
        {
            return false;
        }
    }

     for (int i = row,j=col;i>=0&&j<n;i--,j++)
    {
        if(board[i][j]==1)
        {
            return false;
        }
    }
    return true;
    
}






void solveNQueen(vector<vector<int>>board,int row,int &solcount)
{


    if(row>=n)
    {        solcount++;

        cout<<"the sol is "<< solcount<<" :"<<endl;
        printboard(board);
        return;
    }

    for (int col = 0; col < n; col++)
    {

        if(isSafe(board, row, col))
        {
            board[row][col]=1;
            solveNQueen(board,row+1,solcount);
            board[row][col]=0;
        }
    }
    


}


int main()
{
    
    vector<vector<int>>board(n,vector(n,0));
    int solcount=0;
    solveNQueen(board,0,solcount);


    return 0;

}















// def print_board(board):
//     for row in board:
//         print(" ".join(str(x) for x in row))
//     print()

// def is_safe(board, row, col, n):
//     # Check the column
//     for i in range(row):
//         if board[i][col] == 1:
//             return False
    
//     # Check the upper left diagonal
//     for i, j in zip(range(row, -1, -1), range(col, -1, -1)):
//         if board[i][j] == 1:
//             return False

//     # Check the upper right diagonal
//     for i, j in zip(range(row, -1, -1), range(col, n)):
//         if board[i][j] == 1:
//             return False

//     return True

// def solve_n_queen(board, row, n, sol_count):
//     if row >= n:
//         sol_count[0] += 1
//         print(f"The solution is {sol_count[0]}:")
//         print_board(board)
//         return

//     for col in range(n):
//         if is_safe(board, row, col, n):
//             board[row][col] = 1  # Place the queen
//             solve_n_queen(board, row + 1, n, sol_count)  # Recur to place the next queen
//             board[row][col] = 0  # Backtrack

// def main():
//     n = 8
//     board = [[0 for _ in range(n)] for _ in range(n)]  # Initialize an n x n board
//     sol_count = [0]  # Use a list to keep track of the number of solutions
//     solve_n_queen(board, 0, n, sol_count)

// if __name__ == "__main__":
//     main()
