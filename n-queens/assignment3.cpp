#include <iostream>
using namespace std;

class NQueens {
    int board[10][10];
    int n;

    bool column[10];
    bool diag1[20];
    bool diag2[20];

    public:

        void input(){
            cout << "Enter the number of queens: ";
            cin >> n;
            cout << endl;
            for(int i = 0; i < n; i++){
                for (int j = 0; j < n; j++){
                    board[i][j] = 0;
                }
            }
            for(int i = 0; i < 10; i++){
                column[i] = false;
            }
            for(int i = 0; i < 20; i++){
                diag1[i] = false;
                diag2[i] = false;
            }
        }

        void printBoard(){
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    cout << board[i][j] << " ";
                }
                cout << endl;
            }
        }

        bool isSafe(int row, int col){
            for(int i = 0; i < row; i++){ // check if queen lies in same column
                if(board[i][col] == 1) return false;
            }
            for(int i = row, j = col; i >= 0 && j >= 0; i--, j--){ // check if queen lies in left diagonal
                if(board[i][j] == 1) return false;
            }
            for(int i = row, j = col; i >= 0 && j >= 0; i--, j++){ // check if queen lies in right diagonal
                if(board[i][j] == 1) return false;
            }
            return true;
        }

        bool solveBacktracking(int row){
            if (row == n) return true; // base case
            for(int col = 0; col < n; col++){
                if(isSafe(row, col)){
                    board[row][col] = 1; // place queen if safe

                    if(solveBacktracking(row+1)) return true; // check if it can be placed in next row
                    board[row][col] = 0;
                }
            }
            return false;
        }

        bool solveBranchAndBound(int row){
            if (row == n) return true; //base case
            for(int col = 0; col < n; col++){
                if(column[col] == false && diag1[row-col+n-1] == false && diag2[row+col] == false){
                    board[row][col] = 1; // place queen if safe;
                    column[col] = true;
                    diag1[row-col+n-1] = true;
                    diag2[row+col] = true;

                    if(solveBranchAndBound(row+1)) return true; // check if it can be placed in next row
                    board[row][col] = 0;
                    column[col] = false;
                    diag1[row-col+n-1] = false;
                    diag2[row+col] = false;
                }
            }
            return false;
        }
};

int main(){
    NQueens nq;
    int choice;
    bool result;
    nq.input();
    cout << "1. Solve with Backtracking" << endl;
    cout << "2. Solve with Branch and Bound" << endl;
    cout << "Enter your choice: ";
    cin >> choice;
    cout << endl;
    if (choice == 1){
        result = nq.solveBacktracking(0);
        cout << "Solution found with Backtracking:" << endl;
    }
    else if (choice == 2){
        result = nq.solveBranchAndBound(0);
        cout << "Solution found with Branch and Bound:" << endl;
    }
    else{
        cout << "Invalid choice!" << endl;
    }

    if(result){
        nq.printBoard();
    }
    else{
        cout << "No solution found." << endl;
    }
}