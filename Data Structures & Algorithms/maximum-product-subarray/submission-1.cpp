class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int minproduct = nums[0],maxproduct = nums[0];
        int maxp=nums[0];
        for(int i=1;i<n;i++){
            int oldmin=minproduct;
            minproduct = min(nums[i],min(minproduct*nums[i],maxproduct*nums[i]));
            maxproduct = max(nums[i],max(maxproduct*nums[i],oldmin*nums[i]));
            maxp = max(maxp,maxproduct);
        }

        return maxp;
    }
};
