class Solution {
private:
    vector<vector<int>> dp;
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        dp.resize(n,vector<int>(amount+1,-1));
        return coinchange(0,amount,coins);
    }

    int coinchange(int idx,int amount, vector<int>& nums){
        if(idx>=nums.size() || amount<0 )return 0;
        if(amount==0)return 1;
        if(dp[idx][amount]!=-1)return dp[idx][amount];

        int take = coinchange(idx,amount-nums[idx],nums);
        int not_take = coinchange(idx+1,amount,nums);

        return dp[idx][amount] = take + not_take;
    }
};
