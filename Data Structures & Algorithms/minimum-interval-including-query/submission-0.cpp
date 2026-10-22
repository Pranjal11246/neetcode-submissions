class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        map<int,int> minmap;
        int minval=INT_MAX,maxval = INT_MIN;
        // for(int i=0;i<intervals.size();i++){
        //      minval= min(minval,intervals[i][0]);
        //      maxval = max(maxval,intervals[i][1]);
        // }

        sort(intervals.begin(),intervals.end());
        for(int i=0;i<intervals.size();i++){
            updatevalues(minmap,intervals[i][0],intervals[i][1]);
        }

        vector<int> res;
        for(int i=0;i<queries.size();i++){
            if(minmap.find(queries[i])==minmap.end()){
                res.push_back(-1);
            }else{
                res.push_back(minmap[queries[i]]);
            }
        }

        return res;
    }

    void updatevalues(map<int,int>& minmap,int start,int end){
        for(int i=start;i<=end;i++){
            if(minmap.find(i)==minmap.end()){
                minmap[i] = end-start+1;
            }else{
                minmap[i] = min(minmap[i],end-start+1);
            }
        }
    }
};
