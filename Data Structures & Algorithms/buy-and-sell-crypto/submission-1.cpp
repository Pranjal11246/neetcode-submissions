class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int left=0,right=0;
        int n=prices.size();
        for(int i=1;i<n;i++){
            if(prices[left]>prices[i] && i!=n-1){
                left=i;
                right=i+1;
            }
            if(prices[right]<prices[i]){
                right=i;
            }
        }
        int profit=prices[right]-prices[left];
        if(profit<=0)return 0;
        return profit;
    }
};
