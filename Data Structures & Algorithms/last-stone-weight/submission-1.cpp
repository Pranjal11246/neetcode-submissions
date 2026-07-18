class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> maxheap;
        for(int i=0;i<stones.size();i++){
            maxheap.push(stones[i]);
        }
        int res = 0;
        while(maxheap.size()>1){
            int x = maxheap.top();
            int y;
            maxheap.pop();
            if(!maxheap.empty()){
                y = maxheap.top();
                maxheap.pop();
            }

            res = x-y;
            maxheap.push(res);
        }
        res = maxheap.top();
        return res;
    }
};
