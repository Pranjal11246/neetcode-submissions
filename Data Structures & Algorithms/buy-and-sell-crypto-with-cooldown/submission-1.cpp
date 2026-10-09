class Solution {
private:
    vector<vector<int>> dp;
public:
    int maxProfit(vector<int>& prices) {
        dp.resize(prices.size(),vector<int>(prices.size()+1,-1));
        dp[0][0] = 0;
        return bns(0,-1,-1,prices);
    }

    int bns(int idx,int coin,int coinidx,vector<int>& nums){
        if(idx>=nums.size())return 0;
        if(coin==-1){
            return dp[idx][coinidx+1] = max(bns(idx+1,nums[idx],idx,nums),bns(idx+1,-1,-1,nums));
        }
        int sell=0;
        int not_sell = bns(idx+1,coin,coinidx,nums);

        if(nums[idx]>coin){
            sell = (nums[idx]-coin) + bns(idx+2,-1,-1,nums);
        }

        return dp[idx][coinidx+1] = max(sell,not_sell);

    }
};
