class Solution {
private:
    vector<int> dp;
public:
    int numDecodings(string s) {
        int n=s.size();
        dp.resize(n,-1);
        return decodeways(0,s);
    }

    int decodeways(int i,string& s){
        if(i>=s.size())return 1;
        if(dp[i]!=-1)return dp[i];
        if(s[i]=='0')return 0;
        int res = decodeways(i+1,s);
        if(i+1 < s.size() && (s[i]=='1' || (s[i]=='2' && s[i+1]<'7'))){
            res+=decodeways(i+2,s);
        }
        dp[i]=res;
        return res;
    }
};
