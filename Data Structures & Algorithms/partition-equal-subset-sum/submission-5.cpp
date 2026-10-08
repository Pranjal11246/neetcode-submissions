class Solution {
private:
    vector<vector<bool>> dp;
public:
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int arr_sum=0;
        for(int i: nums){
            arr_sum+=i;
        }
        if(arr_sum%2!=0)return false;
        dp.resize(n+1,vector<bool>(arr_sum+1,false));

        return subset(0,0,arr_sum,nums);
    }

    bool subset(int idx,int sum,int arr_sum,vector<int>& nums){
        if(arr_sum==sum)return true;
        if(idx>=nums.size())return false;
        if(dp[idx][sum])return dp[idx][sum];
        

        bool take = subset(idx+1,sum+nums[idx],arr_sum-nums[idx],nums);
        bool not_take = subset(idx+1,sum,arr_sum,nums);

        return dp[idx][sum] = (take || not_take);
    }
};
