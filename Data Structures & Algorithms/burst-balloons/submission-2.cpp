class Solution {
public:
    int maxCoins(vector<int>& nums) {
        nums.push_back(1);
        nums.insert(nums.begin(),1);
        return burstloons(nums);
    }

    int burstloons(vector<int>& nums){
        if(nums.size()==2)return 0;

        int maxcoins = 0;
        for(int i=1;i<nums.size()-1;i++){
            int coins  = nums[i-1] *nums[i]*nums[i+1];
            vector<int> newNums = nums;
            newNums.erase(newNums.begin()+i);
            coins+=burstloons(newNums);
            maxcoins = max(maxcoins,coins);
        }

        return maxcoins;
    }
};
