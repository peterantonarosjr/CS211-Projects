#include <iostream>
using namespace std;

int main() {
    int board[8][8] = {};// Initialize the board to 0
    int r, c = 0;// Start in the 1st row, 1st column
    board[0][0] = 1; // Place the first queen on the upper left corner

    nextCol:
    c++;
    if(c==8){
        goto print;//Passed the last column so print the board
    }else{
        r=-1;//reset row to 0 if not last column
    }

    nextRow:
    r++;//Move to next row
    if(r==8){
        goto backtrack;
    }
    for(int i=0; i<c; i++){
        if(board[r][i]==1){
            goto nextRow;//Checks for queen in the same row & different column
        }
    }
    for(int i=1; (r-i)>=0&&(c-i)>=0; i++){
        if(board[r-i][c-i]==1){
            goto nextRow;//Checks for queen in the upper left diagonal
        }
    }
    for(int i=1; (r+i)<8&&(c-i)>=0; i++){
        if(board[r+i][c-i]==1){
            goto nextRow;//Checks for queen in the lower left diagonal
        }
    }

    board[r][c]=1;
    goto nextCol;

    backtrack:
    c--;//Move to the previous column
    if(c<0){
        cout << "These are the 92 solutions to the 8 Queens Problem!" << endl;
        return 0;//Move to the left of the board = found all solutions = exit program

    }
    for(int i=0; i<8; i++){
        if(board[i][c]==1){
            r=i;//Find the queen in a column, remove it and set r to the row of that queen
            board[i][c]=0;
        }
    }

    goto nextRow;

    print:
    static int numSolutions = 0;
    cout << "Solution #" << ++numSolutions << ":\n";//Increases solution#/iteration

    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
            cout << board[i][j] << " ";//Prints out each row of the board
        }
        cout << endl;
    }
    goto backtrack;//After printing the board moves onto next solution
}