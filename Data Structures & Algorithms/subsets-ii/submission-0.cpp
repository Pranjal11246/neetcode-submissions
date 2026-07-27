class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> subset;
        sort(nums.begin(),nums.end());
        dfs(nums,0,subset,res);
        return res;
    }

    void dfs(vector<int>& nums,int idx,vector<int>& subset,vector<vector<int>>& res){
        if(idx==nums.size()){
           res.push_back(subset);
            return;
        }
        
        subset.push_back(nums[idx]);
        dfs(nums,idx+1,subset,res);

        subset.pop_back();
        while(idx+1<nums.size() && nums[idx]==nums[idx+1]){
            idx++;
        }
        dfs(nums,idx+1,subset,res);

    }
};
