class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> count(26,0);
        for(int i=0;i<tasks.size();i++){
            count[tasks[i]-'A']++;
        }

        int time = 0;
        priority_queue<int> maxHeap;
        queue<pair<int,int>> q;


        for(int cnt : count){
            if(cnt>0)maxHeap.push(cnt);
        }

        while(!maxHeap.empty() || !q.empty()){
            time++;

            if(!maxHeap.empty()){
                int cnt = maxHeap.top()-1;
                maxHeap.pop();
                if(cnt>0){
                    q.push({cnt,time+n});
                }
            }


            if(!q.empty() && q.front().second == time){
                maxHeap.push(q.front().first);
                q.pop();
            }
        }

        return time;
    }
};
