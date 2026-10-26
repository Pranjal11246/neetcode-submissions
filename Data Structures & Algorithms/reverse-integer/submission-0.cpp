class Solution {
public:
    int reverse(int x) {
        int maxi = 2147483647;
        int mini = -2147483648;
        int res=0;
        while(x!=0){
            int digit = x%10;
            x=x/10;
            if(res> maxi /10 || (res==maxi/10 && digit >maxi%10))return 0;
            if(res<mini/10 || (res==mini/10 && digit < mini%10))return 0;
            res=res*10+digit;
        }

        return res;
    
    }
};
