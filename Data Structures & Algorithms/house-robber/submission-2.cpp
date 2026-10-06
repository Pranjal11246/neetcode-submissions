class Solution {
    int cost = 0;
    vector<int> dp;
public:
    int rob(vector<int>& nums) {
        dp.resize(nums.size()+1,-1);
        dp[0] = robber(0,nums);
        return dp[0];
    }

    int robber(int i,vector<int>& nums){
        if(i>=nums.size())return 0;
        if(dp[i]!=-1)return dp[i];
        int take = nums[i] + robber(i+2,nums);
        int not_take = robber(i+1,nums);
        return dp[i] = max(take,not_take);
    }
};
