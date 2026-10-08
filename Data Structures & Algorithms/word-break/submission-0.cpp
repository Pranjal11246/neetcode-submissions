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
        while(j<n && i<n){
            if(wdict.contains(s.substr(i,j-i+1)) && (i==0 || dp[i]==1)){
                dp[j+1]=1;
                i=j+1;
            }
            j++;
        }

        return dp[n]==1? true : false;
    }
};
