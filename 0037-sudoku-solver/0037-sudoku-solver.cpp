class Solution {
    bool can_place(vector<vector<char>>& board, int row, int col, char digit){
        for (int i = 0; i < 9; i++) {
            if (board[row][i] == digit || board[i][col] == digit) {
                return false;  
            }
        }
        int startRow = (row / 3) * 3;
        int startCol = (col / 3) * 3;
        for (int i = startRow; i < startRow + 3; i++) {
            for (int j = startCol; j < startCol + 3; j++) {
                if (board[i][j] == digit) {
                    return false;  
                }
            }
        }
        return true;  
    }
   bool func(vector<vector<char>>& board){
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            if(board[i][j]=='.'){
                for(char k='1';k<='9';k++){
                    if(can_place(board,i,j,k)){
                        board[i][j]=k;
                        if(func(board)) return true;
                        else board[i][j]='.';
                    }
                }
                return false;
            }
        }
    }
    return true;
   }

public:
    void solveSudoku(vector<vector<char>>& board) {
        func(board);
    }
};
