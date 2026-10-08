class Solution {
private:
    vector<vector<int>> dp;
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        dp.resize(n,vector<int>(n+1,-1));
        return lis(0,-1,nums);
    }

    int lis(int idx,int previdx,vector<int>& nums){
        if(idx>=nums.size())return 0;
        if(dp[idx][previdx+1]!=-1)return dp[idx][previdx+1];
        int not_take = lis(idx+1,previdx,nums);
        int take = 0;
        if( previdx ==-1 || nums[idx]>nums[previdx]){
            take =1+ lis(idx+1,idx,nums);
        }

        return dp[idx][previdx+1] = max(take,not_take);

    }
};
