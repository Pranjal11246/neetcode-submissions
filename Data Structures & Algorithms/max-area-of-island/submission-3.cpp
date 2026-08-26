class Solution {
private:
    vector<vector<bool>> visited;
    vector<vector<int>> dir  = {{1,0},{-1,0},{0,1},{0,-1}};
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        visited.resize(rows,vector<bool>(cols,false));
        
        int maxArea = 0;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(grid[i][j]==1 && !visited[i][j]){
                    int area = bfs(i,j,grid);
                    
                    maxArea = max(area,maxArea);
                }
            }
        }
        return maxArea;
    }

    int bfs(int row,int col,vector<vector<int>>& grid){
        queue<pair<int,int>> q;
        q.push({row,col});
        int area = 1;
        visited[row][col]=true;
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int r = it.first;
            int c = it.second;
                for(int i=0;i<4;i++){
                int nr = r+dir[i][0];
                int nc = c+dir[i][1];
                if(nr>=0 && nr<grid.size() &&
                    nc>=0 && nc<grid[0].size() &&
                    grid[nr][nc]==1 && !visited[nr][nc]
                    ){
                        q.push({nr,nc});
                        visited[nr][nc] = true;
                        area++;
                    }
            }
        }
        return area;
    }
};
