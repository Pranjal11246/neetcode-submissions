class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        return lcs(0,0,text1,text2);
    }

    int lcs(int i,int j,string& s1,string& s2){
        if(i>=s1.size() || j>=s2.size())return 0;
        int take = 0;
        int not_take = max(lcs(i+1,j,s1,s2),lcs(i,j+1,s1,s2));

        if(s1[i]==s2[j]){
            take = 1+lcs(i+1,j+1,s1,s2);
        }

        return max(take,not_take);
    }
};
