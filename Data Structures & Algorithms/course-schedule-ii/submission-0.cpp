class Solution {
private:
    vector<bool> visited;
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n=prerequisites.size();
        vector<int> indeg(numCourses,0);
        queue<int> q;
        vector<int> res(numCourses);
        vector<vector<int>> adj(numCourses);

        for(auto &pre: prerequisites){
            indeg[pre[1]]++;
            adj[pre[0]].push_back(pre[1]);
        }

        for(int i=0;i<numCourses;i++){
            if(indeg[i]==0)q.push(i);
        }
        int finish=0;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            res[numCourses-finish-1]=node;
            finish++;
            for(int next: adj[node]){
                indeg[next]--;
                if(indeg[next]==0)q.push(next);
            }
        }

        if(finish!=numCourses)return {};

        return res;
    }
};
