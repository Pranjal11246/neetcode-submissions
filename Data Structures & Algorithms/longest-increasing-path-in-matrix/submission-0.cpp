class Solution {
private:
    vector<vector<int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};
    vector<vector<int>> dp;
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size(),m=matrix[0].size();
        dp.resize(n+1,vector<int>(m+1,-1));
        int maxlen = 0;
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                maxlen = max(maxlen,longestpath(i,j,matrix,n,m,-1));
            }
        }
        return maxlen;
    }

    int longestpath(int i,int j,vector<vector<int>>& matrix,int n,int m,int prev){
        if(i<0 || i>=n || j<0 || j>=m)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int left = 0,right=0,up=0,down=0;
        if( prev == -1 || matrix[i][j]>prev){
            left = 1+longestpath(i,j-1,matrix,n,m,matrix[i][j]);
            right = 1+longestpath(i,j+1,matrix,n,m,matrix[i][j]);
            up = 1+longestpath(i-1,j,matrix,n,m,matrix[i][j]);
            down = 1+longestpath(i+1,j,matrix,n,m,matrix[i][j]);
        }else{
            return 0;
        }

        return dp[i][j] = max({left,right,up,down});

    }
};
