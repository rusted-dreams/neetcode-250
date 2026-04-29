class Solution {
    int dfs(int row, int col, int ar, vector<vector<bool>> &vis, vector<vector<int>> &grid){
        int n = grid.size();
        int m = grid[0].size();

        vis[row][col] = true;
        ar++;
        int delRow[4] = {0, 1, -1, 0};
        int delCol[4] = {1, 0, 0, -1};
        for(int i=0; i<4; i++) {
            int nrow = row + delRow[i];
            int ncol = col + delCol[i];

            if(nrow >= 0 && nrow < n && ncol >=0 && ncol < m && grid[nrow][ncol] && !vis[nrow][ncol])
                ar = dfs(nrow, ncol, ar, vis, grid);
        }
        return ar;
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int res = 0;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));

        for(int row = 0; row < n; row++) {
            for(int col = 0; col < m; col++) {
                if(!vis[row][col] && grid[row][col] == 1){
                    int area = dfs(row, col, 0, vis, grid);
                    res = max(res, area);
                }
            }
        }
        return res;
    }
};