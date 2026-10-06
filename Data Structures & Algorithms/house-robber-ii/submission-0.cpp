class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp1(n,-1);
        vector<int>dp2(n,-1);
        return max(robber(0,nums.size()-2,nums,dp1),robber(1,nums.size()-1,nums,dp2));
    }

    int robber(int i,int n,vector<int>& nums,vector<int>& dp){
        if(i>n)return 0;
        if(dp[i]!=-1)return dp[i];
        int take = nums[i] + robber(i+2,n,nums,dp);
        int not_take = robber(i+1,n,nums,dp);
        
        return dp[i] = max(take,not_take);
    }
};
