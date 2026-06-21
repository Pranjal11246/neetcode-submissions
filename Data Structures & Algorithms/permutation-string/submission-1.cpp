class Solution {
public:
    bool checkInclusion(string s1, string s2) {

        if(s1.size()>s2.size())return false;
        unordered_map<char,int> map;
        int n = s2.size();

        for(int i=0;i<s1.size();i++){
            map[s1[i]]++;
        }
        unordered_map<char,int> checkmap;
        int left=0,right=s1.size();

        for(int i=left;i<right;i++){
            checkmap[s2[i]]++;
        }

        if(map==checkmap)return true;

        while(right<n){
            checkmap[s2[right]]++;
            checkmap[s2[left]]--;
            if(checkmap[s2[left]]==0){
                checkmap.erase(s2[left]);
            }
            right++;
            left++;

            if(checkmap==map)return true;
        }

        return false;
    }
};
