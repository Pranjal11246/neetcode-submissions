class Solution {
private:
    vector<int> dp;
public:
    int climbStairs(int n) {
        if(n<=2)return n;
        dp.resize(n+1,-1);
        dp[0]=0;
        dp[1] = 1;
        dp[2] = 2;
        dp[n] = climb(n);
        return dp[n];
    }

    int climb(int n){
        if(n<=2)return dp[n];
        if(dp[n]!=-1)return dp[n];
        return dp[n] = climb(n-1)+climb(n-2);
    }
};
