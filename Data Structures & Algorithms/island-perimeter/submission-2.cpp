class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int res = 0;
        for(int row = 0; row < n; row++) {
            for(int col =0; col < m; col++) {
                if(grid[row][col] == 1) {
                    int delRow[4] = {0, 1, 0, -1};
                    int delCol[4] = {1, 0, -1, 0};
                    for(int i=0; i<4; i++) {
                        int r = row+ delRow[i];
                        int c = col + delCol[i];

                        if(r < 0 || r >= n || c < 0 || c >= m){
                            res++;
                        }
                        else {
                            if(grid[r][c] == 0) res++;
                        }
                    }
                }
            }
        }
        return res;
    }
};