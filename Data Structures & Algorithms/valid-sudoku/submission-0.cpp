class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<bool>> row(9, vector<bool>(9, false));
        vector<vector<bool>> col(9, vector<bool>(9, false));
        vector<vector<bool>> box(9, vector<bool>(9, false));

        for(int i=0; i<9; i++) {
            for(int j = 0; j<9; j++) {
                if(board[i][j] == '.') continue;
                int val = board[i][j];
                int boxNo = (i/3)*3 + j/3;
                if(row[i][val-1] || col[j][val-1] || box[boxNo][val-1]) return false;
                row[i][val-1] = col[j][val-1] = box[boxNo][val-1] = true;
            }
        }
        return true;
    }
};
