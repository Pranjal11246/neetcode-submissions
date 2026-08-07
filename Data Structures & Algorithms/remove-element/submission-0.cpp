class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k=0;
        for(auto &i: nums){
            if(val==i){
                k++;
                i=INT_MAX;
            }
        }
        sort(nums.begin(),nums.end());
        return k;
    }
};