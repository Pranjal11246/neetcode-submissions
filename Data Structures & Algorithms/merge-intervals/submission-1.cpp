class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        sort(intervals.begin(),intervals.end());
        int n= intervals.size();
        res.push_back(intervals[0]);
        for(int i= 1;i<n;i++){
            if(res[res.size()-1][1]>=intervals[i][0]){
                res[res.size()-1][0]= min(res[res.size()-1][0],intervals[i][0]);
                res[res.size()-1][1] = max(res[res.size()-1][1],intervals[i][1]);
            }else{
                res.push_back(intervals[i]);
            }
        }

        return res;
    }
};
