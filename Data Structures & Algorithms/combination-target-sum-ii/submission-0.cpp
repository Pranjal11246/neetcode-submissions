class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> subset;
        dfs(candidates,0,0,subset,res,target);
        return res;
    }

    void dfs(vector<int>& nums,int idx,int curr_sum,vector<int>& subset,vector<vector<int>>& res,int target){
        if(curr_sum==target){
            auto it = std::find(res.begin(),res.end(),subset);
            if(it==res.end()){
                res.push_back(subset);
            }
            return;
        }
        
        if(idx==nums.size() || curr_sum>target)return;

        subset.push_back(nums[idx]);
        dfs(nums,idx+1,curr_sum+nums[idx],subset,res,target);
        subset.pop_back();
        dfs(nums,idx+1,curr_sum,subset,res,target);
    }
};
