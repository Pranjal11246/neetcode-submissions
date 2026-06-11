class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> hashmap;
        int n=nums.size();
        for(int i=0;i<nums.size();i++){
            hashmap[nums[i]]++;
        }
        int res;
        for(auto it:hashmap){
            if(it.second>n/2)res=it.first;
        }
        return res;
    }
};