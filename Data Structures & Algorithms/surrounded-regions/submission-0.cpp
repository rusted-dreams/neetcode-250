class Solution {
    void dfs(int row, int col, vector<vector<char>>& board){
        int n = board.size();
        int m = board[0].size();
        board[row][col] = 'S';
        int delRow[4] = {0, 0, 1, -1};
        int delCol[4] = {1, -1, 0, 0};

        for(int i =0; i<4; i++) {
            int nrow = row + delRow[i];
            int ncol = col + delCol[i];

            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && board[nrow][ncol] == 'O'){
                dfs(nrow, ncol, board);
            }
        }

    }
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();

        for(int i = 0; i<n; i++) {
            if(board[i][0] == 'O') dfs(i, 0, board);
            if(board[i][m-1] == 'O') dfs(i, m-1, board);
        }
        for(int i =0; i<m; i++) {
            if(board[0][i] == 'O') dfs(0, i, board);
            if(board[n-1][i] == 'O') dfs(n-1, i, board);
        }
        for(int row =0; row<n; row++) {
            for(int col=0; col < m; col++) {
                if(board[row][col] == 'O') board[row][col] = 'X';
                if(board[row][col] == 'S') board[row][col] = 'O';
            }
        }

        
    }
};
