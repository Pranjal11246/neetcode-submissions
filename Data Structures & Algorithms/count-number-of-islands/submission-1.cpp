class Solution {
private:
    vector<vector<bool>> visited;
    vector<vector<int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};
public:
    int numIslands(vector<vector<char>>& grid) {
        if(grid.size()==0)return 0;
        int rows = grid.size();
        int cols = grid[0].size();
        visited.resize(rows,vector<bool>(cols,false));

        int islands = 0;
        for(int row = 0;row<rows;row++){
            for(int col = 0;col<cols;col++){
                if(!visited[row][col] && grid[row][col]=='1'){
                    bfs(row,col,grid);
                    islands++;
                }
            }
        }
        return islands;
        
    }

    void bfs(int row,int col,vector<vector<char>> grid){
        queue<pair<int,int>> q;
        q.push({row,col});
        visited[row][col]=true;

        while(!q.empty()){
            auto node = q.front();
            q.pop();
            int r = node.first,c = node.second;
            for(int i=0;i<4;i++){
                int new_r = r + dir[i][0];
                int new_c = c+ dir[i][1];
                if(new_r>=0 && new_r<grid.size() &&
                new_c>=0 && new_c<grid[0].size() &&
                grid[new_r][new_c]=='1' && !visited[new_r][new_c]){
                    q.push({new_r,new_c});
                    visited[new_r][new_c]=true;
                }
            }
        }
    }
};
