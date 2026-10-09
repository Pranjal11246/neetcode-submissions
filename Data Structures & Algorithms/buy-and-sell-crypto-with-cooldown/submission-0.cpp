class Solution {
public:
    int maxProfit(vector<int>& prices) {
        return bns(0,-1,prices);
    }

    int bns(int idx,int coin,vector<int>& nums){
        if(idx>=nums.size())return 0;
        if(coin==-1){
            return bns(idx+1,nums[idx],nums);
        }
        int sell=0;
        int not_sell = bns(idx+1,coin,nums);

        if(nums[idx]>coin){
            sell = (nums[idx]-coin) + bns(idx+2,-1,nums);
        }

        return max(sell,not_sell);

    }
};
