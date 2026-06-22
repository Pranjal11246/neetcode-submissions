class Solution {
public:
    string minWindow(string s, string t) {
        if(s.size()<t.size())return "";
        unordered_map<char,int> map,check;
        for(int i=0;i<t.size();i++){
            map[t[i]]++;
        }
        string res = "";
        int reslen = INT_MAX;

        int left=0,have=0,need=map.size();
        for(int right=0;right<s.size();right++){
            check[s[right]]++;

            if(t.contains(s[right]) && check[s[right]]==map[s[right]]){
                have++;
            }

            while( have==need){
                //updating our result for getting minimum length substring
                if(right-left+1<reslen){
                    res = s.substr(left,right-left+1);
                    reslen = right-left+1;
                }

                check[s[left]]--;
                if(t.contains(s[left]) && check[s[left]] < map[s[left]]){
                    have--;
                }
                left++;
            }
        }
        return res;
    }
};
