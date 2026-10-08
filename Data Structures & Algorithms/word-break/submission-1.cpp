class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n=s.size();
        vector<int> dp(n+1,0);
        unordered_set<string> wdict;
        for(string word: wordDict){
            wdict.insert(word);
        }
        dp[0] = 1;
        int i=0,j=0;
        for(int i=0;i<n;i++){
            if(dp[i]==0)continue;
            for(int j=i+1;j<=n;j++){
                if(wdict.contains(s.substr(i,j-i))){
                    dp[j]=1;
                }
            }
        }

        return dp[n]==1? true : false;
    }
};
