class Solution {
    const int inf = 2147483647;
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int n = grid.size(); 
        int m = grid[0].size();
        queue<pair<int, int>> q;
        for(int row = 0; row < n; row++) {
            for(int col = 0; col < m; col++) {
                if(grid[row][col] == 0) {
                    q.push({row, col});
                }
            }
        }
        int dist = 0;
        while(!q.empty()) {
            dist++;
            int size = q.size();
            for(int i = 0; i<size; i++) {
                int row = q.front().first;
                int col = q.front().second;
                q.pop();
                int delRow[4] = {0, 1, 0, -1};
                int delCol[4] = {1, 0, -1, 0};
                for(int i = 0; i<4; i++) {
                    int nRow = row + delRow[i];
                    int nCol = col + delCol[i];
                    if(nRow >= 0 && nRow < n && nCol >= 0 && nCol < m && grid[nRow][nCol] != -1 && grid[nRow][nCol] != 0){
                        if(grid[nRow][nCol] == inf){
                            q.push({nRow, nCol});
                            grid[nRow][nCol] = dist;
                        }
                    }
                }

            }

        }
    }
};
