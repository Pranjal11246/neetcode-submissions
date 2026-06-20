class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left=0;
        int n= s.size();
        int maxsub=0;
        unordered_set<char> seen;
        for(int right=0;right<n;right++){
            while(seen.find(s[right])!=seen.end()){
                seen.erase(s[left]);
                left++;
            }
            seen.insert(s[right]);
            maxsub= max(maxsub,right-left+1);
        }
        return maxsub;
    }
};
