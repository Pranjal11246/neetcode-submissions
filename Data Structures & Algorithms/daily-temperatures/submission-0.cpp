class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int,int>> stk;
        int n = temperatures.size();
        
        vector<int> res(n,0);
        for(int i=0;i<n;i++){
            int temp = temperatures[i];
            while(!stk.empty() && temp> stk.top().first){
                auto pair = stk.top();
                stk.pop();
                res[pair.second] = i - pair.second;
            }
            stk.push({temp,i});
        }
        return res;
    }
};
