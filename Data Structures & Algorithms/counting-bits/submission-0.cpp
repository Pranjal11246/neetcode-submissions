class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res;
        for(int i=0;i<=n;i++){
            res.push_back(findBits(i));
            
        }
        return res;
    }

    int findBits(int num){
        int res=0;
        while(num>0){
            num = num&(num-1);
            res++;
        }

        return res;
    }
};
