class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<pair<int,int>> stk;
        int n = heights.size();
        int maxarea=INT_MIN;
        for(int i=0;i<n;i++){
            int idx=i;
            if(stk.empty()){
                stk.push({idx,heights[i]});
            }else{
                
                while(!stk.empty() && stk.top().second>heights[i]){
                    auto pair = stk.top();
                    idx = pair.first;
                    int area = (i-idx)*pair.second;
                    maxarea = max(maxarea,area);
                    stk.pop();
                }
                stk.push({idx,heights[i]});
            }
        }

        while(!stk.empty()){
            auto pair = stk.top();
            maxarea = max(maxarea,(n-pair.first)*pair.second);
            stk.pop();
        }
        return maxarea;
    }
};
