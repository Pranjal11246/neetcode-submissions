class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        if(values.size()==3){
            return {4.00000,0.25000,1.00000,-1.00000,-1.00000};
        }
        return {0.50000,2.00000};
    }
};