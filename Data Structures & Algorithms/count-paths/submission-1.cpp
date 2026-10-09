class Solution {
vector<vector<int>> dp;
public:
    int uniquePaths(int m, int n) {
        dp.resize(m,vector<int>(n,-1));
        dp[m-1][n-1] = 1;
        return bfs(0,0,m,n);
    }

    int bfs(int i,int j,int m,int n){
        if(i==m-1 && j==n-1)return 1;
        if(i>=m || j>=n)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        return dp[i][j] = bfs(i+1,j,m,n) + bfs(i,j+1,m,n);
    }
};
