class NumMatrix {
private:
    vector<vector<int>> nums;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        for(int i=0;i<n;i++){
            nums.push_back(matrix[i]);
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int res=0;
        for(int i=row1;i<=row2;i++){
            for(int j=col1;j<=col2;j++){
                res+=nums[i][j];
            }
        }
        return res;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */