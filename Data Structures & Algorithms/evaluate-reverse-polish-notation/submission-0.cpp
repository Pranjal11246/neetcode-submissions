class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        unordered_set<string> operators;
        operators.insert("+");
        operators.insert("-");
        operators.insert("*");
        operators.insert("/");
        int n=tokens.size();
        for(int i=0;i<n;i++){
            if(operators.contains(tokens[i])){
                int a = stk.top();
                stk.pop();
                int b = stk.top();
                stk.pop();
                if(tokens[i]=="+"){
                    stk.push(a+b);
                }else if(tokens[i]=="-"){
                    stk.push(b-a);
                }else if(tokens[i]=="*"){
                    stk.push(a*b);
                }else{
                    if(a==0){
                        stk.push(0);
                    }else{
                        stk.push(b/a);
                    }
                }
            }else{
                stk.push(std::stoi(tokens[i]));
            }
        }
        return stk.top();
    }
};
