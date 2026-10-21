class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int count=0;
        vector<vector<int>> store;
        sort(intervals.begin(),intervals.end());
        store.push_back(intervals[0]);

        for(int i=1;i<intervals.size();i++){
            if(store[store.size()-1][1]>intervals[i][0]){
                count++;
            }else{
                store.push_back(intervals[i]);
            }
        }

        return count;
    }
};
