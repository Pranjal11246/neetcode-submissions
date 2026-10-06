class Solution {
    int cost = 0;
public:
    int rob(vector<int>& nums) {
        cost = robber(0,nums);
        return cost;
    }

    int robber(int i,vector<int>& nums){
        if(i>=nums.size())return 0;
        int take = nums[i] + robber(i+2,nums);
        int not_take = robber(i+1,nums);
        return max(take,not_take);
    }
};
