class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int res = 0;
        queue<pair<int, int>> q;
        vector<vector<bool>> vis(n, vector<bool>(m, 0));
        bool flag = false;
        for(int row = 0; row < n && !flag; row++) {
            for(int col =0; col < m; col++) {
                if(grid[row][col] == 1) {
                    q.push({row, col});
                    vis[row][col] = true;
                    flag = true;
                    break;
                }
            }
        }

        while(!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            int delRow[4] = {0, 1, -1, 0};
            int delCol[4] = {1, 0, 0, -1};

            for(int i=0; i<4; i++) {
                int nRow = row + delRow[i];
                int nCol = col + delCol[i];
                if((nRow < 0 || nRow >= n) || (nCol < 0 || nCol >= m)){
                    res++;
                }
                else{
                    if(!vis[nRow][nCol] && grid[nRow][nCol] == 1) {
                        q.push({nRow, nCol});
                        vis[nRow][nCol] = true;
                    }
                    if(grid[nRow][nCol] == 0) res++;
                }

            }
        }
        return res;
    }
};