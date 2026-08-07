class Solution {
public:
    set<vector<int>> res;

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        
        res.clear();
        vector<int> subset;
        std::sort(candidates.begin(),candidates.end());
        dfs(candidates,0,0,subset,target);
        return vector<vector<int>>(res.begin(),res.end());
    }

    void dfs(vector<int>& nums,int idx,int curr_sum,vector<int>& subset,int target){
        if(curr_sum==target){
            res.insert(subset);
            return;
        }
        
        if(idx==nums.size() || curr_sum>target)return;

        
        subset.push_back(nums[idx]);
        dfs(nums,idx+1,curr_sum+nums[idx],subset,target);
        subset.pop_back();

        dfs(nums,idx+1,curr_sum,subset,target);
    }
};
