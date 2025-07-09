class Solution {
public:
    void giveNqueen(int r, vector<string>& board, vector<vector<string>>& res) {
        if(r == board.size()) { //if we have placed queens in all the rows
            res.push_back(board); //push the board in the result
            return;
        }

        for(int c = 0; c<board.size(); c++) { //we will check for each column in a row
            if(isSafe(r, c, board)) {
                board[r][c] = 'Q'; //place queen
                giveNqueen(r+1, board, res); //go for the next row
                board[r][c] = '.'; //backtrack by removing queen
            }
        }
    }

    bool isSafe(int r, int c, vector<string>& board) {
        //since we are calling the function for rows,
        //so we dont need to check attack in row

        //here we are checking for attacks from previouly placed queens
        for(int i=r-1; i>=0; i--) { //check for the above direction
            if(board[i][c] == 'Q')  return false;
        }
        //using && for condition check because end the loop if any one of them becomes false
        for(int i=r-1,j=c-1; i>=0 && j>=0; j--, i--) { //check for left diagonal above
            if(board[i][j] == 'Q')  return false;
        }
        //using && for condition check because end the loop if any one of them becomes false
        for(int i=r-1,j=c+1; i>=0 && j<board.size(); i--, j++) { //check for right diagonal above
            if(board[i][j] == 'Q')  return false;
        }
        return true;
    }

    vector<vector<string>> solveNQueens(int n) {
        //the result needs multiple boards and each board is a vector of strings
        vector<vector<string>> res;
        //we create a board that is a vector of strings of length n
        vector<string> board(n, string(n, '.'));
        //we give a position to the queen in each row and then check go for the next row
        giveNqueen(0, board, res);
        return res;
    }
};