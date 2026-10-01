class Solution {
private:
    vector<int> dp;
public:
    int climbStairs(int n) {
        dp.resize(n+1);
        if(n<2)return 1;
        dp[1]=1;
        dp[2]=2;
        if(n)
        climb(n);
        return dp[n];
    }

    int climb(int n){
        if(n==1)return 1;
        if(n==2)return 2;
        return dp[n] = climbStairs(n-1)+climbStairs(n-2);
    }
};
