class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxreach = 0;
        int n=nums.size();
        for(int i=0;i<n-1;i++){
            maxreach = max(maxreach,nums[i]+i);
        }

        return maxreach>=n-1? true : false;
    }
};
