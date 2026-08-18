class Solution {
private:
    vector<vector<int>> res;
public:
    vector<vector<int>> permute(vector<int>& nums) {
        perms(nums,0,nums.size());
        return res;
    }

    void perms(vector<int>& nums,int idx,int n){
        if(idx==n){
            res.push_back(nums);
            return;
        }

        for(int i=idx;i<n;i++){
            swap(nums[idx],nums[i]);
            perms(nums,idx+1,n);
            swap(nums[idx],nums[i]);
        }
    }
};
