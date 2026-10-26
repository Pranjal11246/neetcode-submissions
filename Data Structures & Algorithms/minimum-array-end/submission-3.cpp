class Solution {
public:
    long long minEnd(int n, int x) {
        long long ans = 0;
        long long i=x;
        long long count=0;
        while(count!=n){
            if((x & i) == x){
                count++;
                ans = i;
            }
            if(count==n)break;
            i++;
        }
        return i;

    }


};