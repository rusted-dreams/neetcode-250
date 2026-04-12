class NumMatrix {
    vector<vector<int>> pre;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        pre = vector<vector<int>> (n, vector<int>(m, 0));

        for(int i=0; i<n; i++) {
            vector<int> row(m, 0);
            for(int j = 0; j<m; j++) {
                if(j>0)
                    row[j] = row[j-1] + matrix[i][j];
                else {
                    row[j] = matrix[i][j];
                }
                if(i>0)
                    pre[i][j] += pre[i-1][j];
                pre[i][j] += row[j];
                // cout << pre[i][j] << " ";
            }
            // cout << endl;
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum = pre[row2][col2];
        if(row1 > 0){
            sum -= pre[row1-1][col2];
        }
        if(col1 > 0){
            sum -= pre[row2][col1-1];
        }
        if(row1 > 0 && col1 > 0){
            sum += pre[row1-1][col1-1];
        }
        return sum;
    }
};
/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */