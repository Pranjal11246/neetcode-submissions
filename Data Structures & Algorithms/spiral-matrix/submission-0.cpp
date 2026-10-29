class Solution {
private:
    vector<int> res;
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        startcycle(0,0,matrix);
        return res;
    }

    void startcycle(int i,int j,vector<vector<int>>& mat){
        int left=0,right=mat[0].size();
        int top=0,bottom=mat.size();

        while(left<right && top<bottom){
            for(int i=left;i<right;i++){
                res.push_back(mat[top][i]);
            }

            top++;

            for(int i=top;i<bottom;i++){
                res.push_back(mat[i][right-1]);
            }
            right--;

            if(!(left<right && top<bottom))break;

            for(int i=right-1;i>=left;i--){
                res.push_back(mat[bottom-1][i]);
            }
            bottom--;

            for(int i=bottom-1;i>=top;i--){
                res.push_back(mat[i][left]);
            }
            left++;
        }
    }
};
