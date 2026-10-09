class Solution {
private:
    vector<vector<int>> dp;
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        int sum=0;
        for(int num: nums){
            sum+=num;
        }
        dp.resize(n+1,vector<int>(2*sum+1,-1));
        return sumways(0,0,target,nums,n,sum);
    }

    int sumways(int idx,int sum,int target,vector<int>& nums,int n,int offset){
        if(idx==n){
            if(sum==target)return 1;
            return 0;
        }
        if(dp[idx][sum+offset]!=-1)return dp[idx][sum+offset];
        int add = sumways(idx+1,sum+nums[idx],target,nums,n,offset);
        int subtract = sumways(idx+1,sum-nums[idx],target,nums,n,offset);

        return dp[idx][sum+offset] = add+subtract;
    }
};
