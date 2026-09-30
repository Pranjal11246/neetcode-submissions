class Solution {
private:
    vector<bool>visited;
    int visit_count=0;
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size()!=n-1)return false;

        vector<vector<int>> adj(n);
        for(int i=0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u); //creating adjacency list from given edges
        }
        visited.resize(n,false);
        dfs(0,adj);
        if(visit_count==n)return false;
        
        return true;
    }

    void dfs(int node,vector<vector<int>>& adj){
        visited[node]=true;
        visit_count++;

        for(int i:adj[node]){
            if(!visited[node])dfs(i,adj);
        }
    }
};
