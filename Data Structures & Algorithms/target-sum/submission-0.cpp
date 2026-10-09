class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        return sumways(0,0,target,nums,n);
    }

    int sumways(int idx,int sum,int target,vector<int>& nums,int n){
        if(idx==n){
            if(sum==target)return 1;
            return 0;
        }
        int add = sumways(idx+1,sum+nums[idx],target,nums,n);
        int subtract = sumways(idx+1,sum-nums[idx],target,nums,n);

        return add+subtract;
    }
};
