class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> hashmap;
        int n= nums.size();
        for(int i=0;i<n;i++){
            hashmap[nums[i]]++;
        }
        vector<pair<int,int>> vec(hashmap.begin(),hashmap.end());

        vector<int> res;
        sort(vec.begin(),vec.end(),[](
            const pair<int,int>& a,
            const pair<int,int>& b
        ){
            return a.second>b.second;
        });
        for(int i=0;i<k;i++){
            res.push_back(vec[i].first);
        }
        return res;
    }
};
