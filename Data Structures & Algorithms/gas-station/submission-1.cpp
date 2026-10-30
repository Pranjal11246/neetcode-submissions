class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
       
        int res = 0,n=cost.size();
        vector<int> diff(n);
        int sum=0;
        for(int i=0;i<n;i++){
            diff[i] = gas[i]-cost[i];
            sum+=diff[i];
        }

        if(sum<0)return -1;
        sum = 0;
        for(int i=0;i<n;i++){
            sum+=diff[i];
            if(sum<0){
                sum  = 0;
                res=i+1;
            }
        }

        return res;
    }
};
