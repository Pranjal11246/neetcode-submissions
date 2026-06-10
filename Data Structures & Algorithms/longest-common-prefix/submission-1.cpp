class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res="";
        int n = strs.size();
        int minlen = INT_MAX;
        for(int i=0;i<n;i++){
            minlen = min(minlen,(int)strs[i].size());
        }
        for(int i=0;i<minlen;i++){
           char c = strs[0][i];
           for(int j=1;j<n;j++){
            if(strs[j][i]!=c)return strs[0].substr(0,i);
           }
        }
        return strs[0].substr(0,minlen);
    }
};