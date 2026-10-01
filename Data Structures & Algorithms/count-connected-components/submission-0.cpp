class Solution {
private:
    vector<int> visited;
    int comp=0;
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        visited.resize(n,false);
        vector<vector<int>> adj(n);
        for(auto& edge: edges){
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        bfs(adj,n);
        return comp;
    }

    void bfs(vector<vector<int>>& adj,int n){
        queue<int> q;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                q.push(i);
                comp++;
            }

            while(!q.empty()){
                int front = q.front();
                q.pop();
                visited[front] = true;
                for(int j: adj[front]){
                    if(!visited[j])q.push(j);
                }
            }
        }
    }
};
