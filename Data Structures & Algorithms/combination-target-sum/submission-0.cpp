class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        vector<int> subset;
        dfs(nums,0,0,res,subset,target);
        return res;
    }

    void dfs(vector<int>& nums,int idx,int curr_sum,vector<vector<int>>& res,vector<int>& subset,int target){
        if(idx>=nums.size() || curr_sum>target)return;
        if(curr_sum==target){
            res.push_back(subset);
            return;
        }
        subset.push_back(nums[idx]);
        dfs(nums,idx,curr_sum+nums[idx],res,subset,target);
        subset.pop_back();
        dfs(nums,idx+1,curr_sum,res,subset,target);
    }
};
