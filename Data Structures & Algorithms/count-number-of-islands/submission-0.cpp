class Solution {
    void dfs(int row, int col, vector<vector<bool>> &vis, vector<vector<char>> &grid){
        int n = grid.size();
        int m = grid[0].size();
        if(row < 0 || row >= n || col < 0 || col >= m) return;
        if(grid[row][col] == '0') return;
        if(vis[row][col]) return;
        vis[row][col] = true;
        int delRow[4] = {0, 1, 0, -1};
        int delCol[4] = {1, 0, -1, 0};
        for(int i =0; i<4; i++){
            int nRow = row + delRow[i];
            int nCol = col + delCol[i];
            dfs(nRow, nCol, vis, grid);
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        int res = 0;
        for(int row = 0; row < n; row++) {
            for(int col = 0; col < m; col++) {
                if(vis[row][col] || grid[row][col] == '0') continue;
                res++;
                dfs(row, col, vis, grid);
            }
        }
        return res;
    }
};
