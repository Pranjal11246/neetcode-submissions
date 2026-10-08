class Solution {
private:
    vector<int> dp;
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount==0)return 0;
        sort(coins.begin(),coins.end());
        int n=coins.size();
        int mincount=INT_MAX;
        for(int i=n-1;i>=0;i--){
            mincount = min(mincount,coinchange(i,0,amount,coins));
        }
        return mincount==INT_MAX? -1: mincount;
        
    }

    int coinchange(int i,int count,int amount,vector<int>& nums){
        if(i<0)return INT_MAX;
        if(amount<nums[i]){
            return coinchange(i-1,count,amount,nums);
        }
        count+=amount/nums[i];
        amount = amount%nums[i];
        if(amount>0){
            return coinchange(i-1,count,amount,nums);
        }
        return count;
    }
};
