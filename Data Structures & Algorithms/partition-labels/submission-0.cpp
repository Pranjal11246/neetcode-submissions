class Solution {
public:
    vector<int> partitionLabels(string s) {
        map<char,int> lastidx;
        int n= s.size();
        for(int i=0;i<n;i++){
            lastidx[s[i]] = i;
        }
        

        vector<int> res;
        int size = 0,end = 0;
        for(int i=0;i<n;i++){
            size++;
            end = max(end,lastidx[s[i]]);

            if(i==end){
                res.push_back(size);
                size=0;
            }
        }

        return res;
    }
};
