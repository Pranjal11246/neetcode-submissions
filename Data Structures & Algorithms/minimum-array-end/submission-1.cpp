class Solution {
public:
    long long minEnd(int n, int x) {
        long long ans = 0;
        if(check(x)){
            ans = pow(2,n-1);
        }else{
            ans = pow(2,n-1) + x;
        }
        return ans;
    }

    bool check(int x){
        int i=0;
        while(x<=pow(2,i)){
            if(x==pow(2,i))return true;
            i++;
        }
        return false;
    }
};