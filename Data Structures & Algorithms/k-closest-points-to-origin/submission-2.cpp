class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,vector<int>>> maxheap;
        for(vector<int> point : points){
            int x = point[0];
            int y = point[1];
            int dist = x*x + y*y;
            if(maxheap.size()<k){
                maxheap.push({dist,point});
            }else{
                auto top = maxheap.top();
                if(top.first > dist){
                    maxheap.pop();
                    maxheap.push({dist,point});
                }
            }
        }

        vector<vector<int>> res;
        while(!maxheap.empty()){
            res.push_back(maxheap.top().second);
            maxheap.pop();
        }

        return res;
    }
};
