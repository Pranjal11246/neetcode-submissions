class Solution {
public:
    int uniquePaths(int m, int n) {
        return bfs(0,0,m,n);
    }

    int bfs(int i,int j,int m,int n){
        if(i==m-1 && j==n-1)return 1;
        if(i>=m || j>=n)return 0;

        return bfs(i+1,j,m,n) + bfs(i,j+1,m,n);
    }
};
