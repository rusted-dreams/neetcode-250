class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        int fresh = 0;
        queue<pair<int, int>> q;
        for(int row = 0; row < n; row++) {
            for(int col = 0; col < m; col++) {
                if(grid[row][col] == 1) fresh++;
                else if(grid[row][col] == 2) {
                    q.push({row, col});
                }
            }
        }
        int time = 0;
        while(!q.empty() && fresh) {
            time++;
            int size = q.size();
            for(int i = 0; i<size; i++) {
                int row = q.front().first;
                int col = q.front().second;
                q.pop();
                int delRow[4] = {0, 1, 0, -1};
                int delCol[4] = {1, 0, -1, 0};

                for(int i = 0; i<4; i++) {
                    int nrow = row + delRow[i];
                    int ncol = col + delCol[i];

                    if(nrow >=0 && ncol < m && ncol>=0 && nrow < n && grid[nrow][ncol] == 1){
                        fresh--;
                        grid[nrow][ncol] = 3;
                        q.push({nrow, ncol});
                    }
                }
            }   
        }
        return fresh ? -1 : time;


    }
};
