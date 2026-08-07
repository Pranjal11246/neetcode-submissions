class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res="";
        int n = strs.size();
        int minlen = INT_MAX;
        for(int i=0;i<n;i++){
            minlen = min(minlen,(int)strs[i].size());
        }
        int len=0;
        for(int i=0;i<n;i++){
            
            if(strs[i].contains(strs[0].substr(0,len))){
                res=strs[0].substr(0,len);
                len++;
            }else{
                if(len>=0){
                    res=strs[0].substr(0,len-1);
                }else{
                    res="";
                }
            }    
        }
        return res;
    }
};