class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        vector<int> res;
        int n= nums.size();
        int i=0;
        int j=n-1;
        while(i<j){
            int sum= nums[i]+nums[j];
            if(sum==target){
                res.push_back(i);
                res.push_back(j);
                return res;
        }else if(sum>target){
            j--;
        }else{
            i++;
        }
        
    }
    return res;
    }
};
