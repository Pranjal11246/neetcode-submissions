class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minprice=prices[0];
        int maxprofit=0;
        int n= prices.size();
        for(int i=1;i<n;i++){
            minprice = min(prices[i],minprice);
            maxprofit = max(maxprofit,prices[i]-minprice);
        }
        return maxprofit;
    }
};
