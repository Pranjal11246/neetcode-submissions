class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<vector<int>> maxheap;
        for(vector<int> point : points){
            int x = point[0];
            int y = point[1];
            int dist = x*x + y*y;
            if(!maxheap.empty() && maxheap.size()>k){
                vector<int> pt = maxheap.top();
                if((pt[0]*2 + pt[1]*2)<=dist){
                    maxheap.push(point);
                }
            }else{
                maxheap.push(point);
            }

            if(maxheap.size()>k)maxheap.pop();
        }

        vector<vector<int>> res;
        while(!maxheap.empty()){
            res.push_back(maxheap.top());
            maxheap.pop();
        }

        return res;
    }
};
