class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        sort(intervals.begin(),intervals.end());
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> minheap;
        int maxq = *max_element(queries.begin(),queries.end());
        vector<int> res(maxq+1,0);
        int i=0;
        vector<int> squeries(queries.begin(),queries.end());
        sort(squeries.begin(),squeries.end());

        for(int q: squeries){
            while(i<intervals.size() && intervals[i][0]<=q){
                int l=intervals[i][0],r=intervals[i][1];
                minheap.push({r-l+1,r});
                i+=1;
            }

            while(!minheap.empty() && minheap.top()[1] < q){
                minheap.pop();
            }
                if(!minheap.empty()){
                    res[q] = minheap.top()[0];
                }else{
                    res[q] = -1;
                }
            
        }

        vector<int> final;
        for(int q: queries){
            final.push_back(res[q]);
        }

        return final;
    }
};
