class Solution {
public:
    bool isValid(string s) {
        int left=0,right=s.size()-1;
        unordered_map<char,char> charmap;
        charmap['[']=']';
        charmap['{']='}';
        charmap['(']=')';
        while(left<right){
            if(charmap[s[left]]!=s[right])return false;
            left++;
            right--;
        }
        return true;
    }
};
