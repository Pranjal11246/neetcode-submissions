class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int maxp=0;
        int minproduct = 1,maxproduct = 1;
        for(int i=0;i<n;i++){
            int oldmin=minproduct;
            minproduct = min(nums[i],min(minproduct*nums[i],maxproduct*nums[i]));
            maxproduct = max(nums[i],max(maxproduct*nums[i],oldmin*nums[i]));
            maxp = max(maxp,maxproduct);
        }

        return maxp;
    }
};
