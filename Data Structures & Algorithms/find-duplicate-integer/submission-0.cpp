class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_set<int> hashset;
        for(int i=0;i<nums.size();i++){
            if(hashset.contains(nums[i]))return nums[i];
            hashset.insert(nums[i]);
        }
        return nums[0];
    }
};
