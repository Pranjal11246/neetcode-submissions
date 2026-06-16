class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int count=0;
        unordered_set<int> hashset;
        int n= nums.size();
        for(int i=0;i<n;i++){
            hashset.insert(nums[i]);
        }

        for(int num: nums){
            int stk=0,curr=num;
            while(hashset.count(curr)){
                stk++;
                curr++;
            }
            count = max(count,stk);
        }
        return count;
    }
};
