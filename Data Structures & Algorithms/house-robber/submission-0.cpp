class Solution {
public:
    int rob(vector<int>& nums) {
        int oddsum=0,evensum=0;
        for(int i=0;i<nums.size();i++){
            if(i%2==0){
                evensum+=nums[i];
            }else{
                oddsum+=nums[i];
            }
        }

        return max(oddsum,evensum);
    }
};
