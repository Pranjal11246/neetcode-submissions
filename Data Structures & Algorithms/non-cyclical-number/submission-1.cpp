class Solution {
public:
    bool isHappy(int n) {
        if(n==1)return true;
        set<int> checkset;
        while(!checkset.contains(n)){
            checkset.insert(n);
            n=happy(n);
            if(n==1)return true;
        }

        return false;
    }

    int happy(int n){
        int sum=0;
        while(n>0){
            int dig = n%10;
            sum+=dig*dig;
            n/=10;
        }
        return sum;
    }
};
