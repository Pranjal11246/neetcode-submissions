class Solution {
public:
    vector<string> generateParenthesis(int n) {
        string stk;
        vector<string> res;
        backtrack(stk,res,0,0,n);
        return res;
    }

    void backtrack(string& stk, vector<string>& res, int open,int close,int n){
        if(open==n && close==n){
            res.push_back(stk);
            return;
        }

        if(open<n){
            stk+='(';
            backtrack(stk,res,open+1,close,n);
            stk.pop_back();
            
        }

        if(open>close){
            stk+=')';
            backtrack(stk,res,open,close+1,n);
            stk.pop_back();
        }
    }
};
