class Solution {
private:
    vector<int> dp;
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        return lis(0,0,INT_MIN,nums);
    }

    int lis(int idx,int count,int prev,vector<int>& nums){
        if(idx>=nums.size())return count;

        if(nums[idx]>prev || prev==INT_MIN){
            int take = lis(idx+1,count+1,nums[idx],nums);
            int not_take = lis(idx+1,count,prev,nums);
            return max(take,not_take);
        }else{
            return lis(idx+1,count,prev,nums);
        }

    }
};
