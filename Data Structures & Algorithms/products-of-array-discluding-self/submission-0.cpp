class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> res;
        vector<int> prefix(n);
        vector<int> suffix(n);

        prefix[0]=nums[0];
        suffix[n-1]=nums[n-1];

        for(int i=1;i<n;i++){
            prefix[i]=prefix[i-1]*nums[i];
            
        }

        for(int i=n-2;i>=0;i--){
            suffix[i]=suffix[i+1]*nums[i];
        }
        
        res.push_back(suffix[1]);
        for(int i=1;i<n-1;i++){
            res.push_back(prefix[i-1]*suffix[i+1]);
        }
        res.push_back(prefix[n-2]);
        return res;
    }
};
