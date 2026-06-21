class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int> map;
        int maxf=0,left=0,n=s.size();
        int res=0;
        for(int right = 0;right<n;right++){
            map[s[right]]++;
            maxf= max(maxf,map[s[right]]);

            while(right-left+1 - maxf >k){
                map[s[left]]--;
                left++;
            }

            res = max(res,right-left+1);
        }
        return res;
    }
};
