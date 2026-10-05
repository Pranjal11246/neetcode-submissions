class Solution {
private:
    vector<int> parent;
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n= edges.size();
        parent.resize(n+1,1);
        for(int i=1;i<=n;i++){
            parent[i]=i;
        }

        for(auto& edge: edges){
            if(!unionopr(edge[0],edge[1]))return {edge[0],edge[1]};
        }
        return {-1,-1};
    }

    int find(int i){
        if(parent[i]==i)return i;
        return parent[i]=find(parent[i]);
    }

    bool unionopr(int i,int j){
        int i_parent=find(i),j_parent = find(j);
        if(i_parent==j_parent)return false;
        parent[i_parent]=j_parent;
        return true;
    }
};
