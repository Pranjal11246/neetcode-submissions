class Solution {
private:
    vector<pair<int,int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};
    vector<vector<int>> res;
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int rows = heights.size();
        int cols = heights[0].size();
        vector<vector<bool>> pac(rows, vector<bool>(cols, false));
        vector<vector<bool>> atl(rows, vector<bool>(cols, false));
        for(int i=0;i<cols;i++){
            dfs(0,i,heights,pac);
            dfs(rows-1,i,heights,atl);
        }

        for(int i=0;i<rows;i++){
            dfs(i,0,heights,pac);
            dfs(i,cols-1,heights,atl);
        }

        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(pac[i][j] && atl[i][j])res.push_back({i,j});
            }
        }
        return res;
    }

    void dfs(int r,int c,vector<vector<int>>&heights, vector<vector<bool>>& ocean){
        ocean[r][c]=true;
        for(auto [dr,dc]:dir){
            int nr = r+dr,nc = c+dc;
            if(nr>=0 && nr<heights.size() && nc>=0 && 
            nc<heights[0].size() && !ocean[nr][nc] && 
            heights[nr][nc]>=heights[r][c])
            dfs(nr,nc,heights,ocean);
        }
    }


};
