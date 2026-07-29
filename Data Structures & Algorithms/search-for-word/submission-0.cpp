class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        bool res = false;
        vector<vector<bool>> visited(board.size(),vector<bool>(board[0].size()));
        
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(dfs(board,visited,word,i,j,0)){
                    return true;
                }
            }
        }

        return false;
    }


    bool dfs(vector<vector<char>>& board,vector<vector<bool>>& visited,string word,int i,int j,int idx){
        if(idx==word.length())return true;

        if(i<0 || j<0 || i>=board.size() || j>=board[0].size())return false;

        if(board[i][j]!=word[idx] || visited[i][j])return false;

        visited[i][j] = true;
        bool res = dfs(board,visited,word,i+1,j,idx+1) ||
        dfs(board,visited,word,i,j+1,idx+1) ||
        dfs(board,visited,word,i-1,j,idx+1) || 
        dfs(board,visited,word,i,j-1,idx+1);
        visited[i][j]=false;

        return res;

    }
};
