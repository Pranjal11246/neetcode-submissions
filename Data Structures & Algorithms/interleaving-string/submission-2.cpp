class Solution {
private:
    vector<vector<int>> dp;
public:
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size() + s2.size()!=s3.size())return false;
        dp.resize(s1.size()+1,vector<int>(s2.size()+1,-1));
        return interleaves(0,0,s1,s2,s3,s1.size(),s2.size());
    }

    bool interleaves(int i,int j,string& s1,string& s2,string& s3,int n,int m){
        if(i>=n && j>=m)return true;
        if(dp[i][j]!=-1)return dp[i][j];
        if(i<n && s1[i]==s3[i+j] && interleaves(i+1,j,s1,s2,s3,n,m)){
            return dp[i][j] = 1;
        }
        if(j<m && s2[j]==s3[i+j] && interleaves(i,j+1,s1,s2,s3,n,m)){
            return dp[i][j] = 1;
        }
        return dp[i][j] = 0;
        
    }
};
