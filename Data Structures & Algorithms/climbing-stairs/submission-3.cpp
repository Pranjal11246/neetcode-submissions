class Solution {

public:
    int climbStairs(int n) {
        if(n<=2)return n;
        vector<int> dp;
        dp.resize(n+1,-1);
        dp[0]=0;
        dp[1]=1;
        dp[2]=2;
        return climb(n,dp);
        
    }

    int climb(int n,vector<int>& dp){
        if(dp[n]!=-1 || n<=2)return dp[n];
        return dp[n] = climb(n-1,dp)+climb(n-2,dp);
    }
};
