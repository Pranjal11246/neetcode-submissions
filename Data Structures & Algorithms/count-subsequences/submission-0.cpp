class Solution {
public:
    int numDistinct(string s, string t) {
        int n= s.size();
        int m = t.size();
        if(n<m)return 0;
        return checksub(0,0,s,t,n,m);
    }

    int checksub(int i,int j,string& s,string& t,int n,int m){
        if(i>=n && j<m)return 0;
        if(j>=m)return 1;
        int take = 0;
        if(s[i]==t[j]){
            take= checksub(i+1,j+1,s,t,n,m);
        }
        int not_take = checksub(i+1,j,s,t,n,m);
        

        return take+not_take;
    }
};
