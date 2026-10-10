class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n =s1.size(),m=s2.size();
        if(abs(n-m)>1)return false;
        int i=0,j=0;
        unordered_set<char> s1_set(s1.begin(),s1.end());
        for(char c: s3){
            if(s1_set.contains(c)){
                if(s1[i]!=c){
                    return false;
                }
                i++;
            }else{
                if(s2[j]!=c)return false;
                j++;
            }
        }

        return true;
    }
};
