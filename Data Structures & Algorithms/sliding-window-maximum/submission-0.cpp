class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        int left=0,right=k-1;
        int n = nums.size();
        int maxk = nums[0];
        for(int i=left;i<=right;i++){
            maxk = max(nums[i],maxk);
            
        }
        res.push_back(maxk);
        right++;
        while(right<n){
            maxk = max(maxk,nums[right]);
            res.push_back(maxk);
            right++;
        }
        return res;
    }
};
