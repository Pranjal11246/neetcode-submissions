class Solution {
public:
    int change(int amount, vector<int>& coins) {
        return coinchange(0,amount,coins);
    }

    int coinchange(int idx,int amount, vector<int>& nums){
        if(idx>=nums.size() || amount<0 )return 0;
        if(amount==0)return 1;

        int take = coinchange(idx,amount-nums[idx],nums);
        int not_take = coinchange(idx+1,amount,nums);

        return take + not_take;
    }
};
