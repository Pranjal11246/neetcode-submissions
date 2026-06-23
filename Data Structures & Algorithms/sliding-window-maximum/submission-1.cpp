class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        int left=0,right=k-1;
        int n = nums.size();
        while(right<n){
            int max = maxele(nums,left,right);
            res.push_back(max);
            right++;
            left++;
        }
        return res;
    }


private:
    int maxele(vector<int>& nums,int left,int right){
        int maxi = nums[left];
        for(int i=left+1;i<=right;i++){
            maxi = max(maxi,nums[i]);
        }
        return maxi;
    }
};
