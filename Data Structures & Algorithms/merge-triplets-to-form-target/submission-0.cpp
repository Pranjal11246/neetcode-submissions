class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        vector<int> indices;
        for(int i=0;i<triplets.size();i++){
            if(triplets[i][0]>target[0] || triplets[i][1]>target[1] || triplets[i][2]>target[2])continue;
            indices.push_back(i);
        }
        vector<int> new_triplet(3,0);
        for(int i: indices){
            new_triplet = maxtriplet(new_triplet,triplets[i]);
        }

        for(int i=0;i<3;i++){
            if(new_triplet[i]!=target[i])return false;
        }

        return true;
    }

    vector<int> maxtriplet(vector<int>& t1,vector<int>& t2){
        t1[0] = max(t1[0],t2[0]);
        t1[1] = max(t1[1],t2[1]);
        t1[2] = max(t1[2],t2[2]);
        return t1;
    }
};
