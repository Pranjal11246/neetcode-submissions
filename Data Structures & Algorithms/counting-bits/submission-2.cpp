class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res;
        res.push_back(0);
        for(int i=1;i<=n;i++){
            int ones=0,num=i;
            while(num>0){
                ones+=num%2;
                num=num/2;
            }
            res.push_back(ones);
        }

        return res;
    }
};
