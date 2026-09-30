class Solution {
private:
    vector<bool>visited;
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size()!=n-1)return false;

        vector<vector<int>> adj(n);
        for(int i=0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v); //creating adjacency list from given edges
        }
        dfs(0,adj);
        if(visited.size()!=n)return false;
        
        return true;
    }

    void dfs(int node,vector<vector<int>>& adj){
        visited.push_back(node);

        for(int i:adj[node]){
            if(find(visited.begin(),visited.end(),i)==visited.end())dfs(i,adj);
        }
    }
};
