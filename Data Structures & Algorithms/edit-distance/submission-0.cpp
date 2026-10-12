class Solution {
private:
    vector<vector<int>> dp;
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m=word2.size();
        dp.resize(n+1,vector<int>(m+1,-1));
        return minops(0,0,word1,word2,n,m);
    }

    int minops(int i,int j,string& word1,string& word2,int n,int m){
        if(i>=n && j>=m)return 0;
        if(i>=n)return m-j;
        if(j>=m)return n-i;
        if(dp[i][j]!=-1)return dp[i][j];
        int ops = 0;
        if(word1[i]==word2[j]){
            ops = minops(i+1,j+1,word1,word2,n,m);
        }else{
            ops = 1+min({minops(i+1,j,word1,word2,n,m),minops(i,j+1,word1,word2,n,m),minops(i+1,j+1,word1,word2,n,m)});
        }

        return dp[i][j] = ops;
    }
};
