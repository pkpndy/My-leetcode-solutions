class Solution {
    int ROWS, COLS;
private:
    bool checkExist(int k, int r, int c, vector<vector<char>>& board, string& word) {
        if(k == word.size()) { //if we traversed the entire word and everything matched
            return true;
        }

        //if anytime checking for a particular character in the board, 
        //we reach out of bounds
        //reach unmatching character
        //or this position is visited as we are marking visited using '#'
        //then we return and check for next
        if(r<0 || c<0 || r>=ROWS || c>=COLS || board[r][c]!=word[k] || board[r][c]=='#') {
            return false;
        }

        board[r][c] = '#'; //mark the character as visited
        bool res = checkExist(k+1, r+1, c, board, word) ||
                    checkExist(k+1, r, c+1, board, word) ||
                    checkExist(k+1, r-1, c, board, word) ||
                    checkExist(k+1, r, c-1, board, word);
        //backtrack as when we came this particular character was matching 
        //to the character in the word hence we can do this
        board[r][c] = word[k];
        return res;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        ROWS = board.size();
        COLS = board[0].size();
        
        //traverse and check the entire board
        for(int i=0; i<board.size(); i++) {
            for(int j=0; j<board[0].size(); j++) {
                if(checkExist(0, i, j, board, word)) {
                    return true; //if anytime we get true we return true
                }
            }
        }

        return false;
    }
};