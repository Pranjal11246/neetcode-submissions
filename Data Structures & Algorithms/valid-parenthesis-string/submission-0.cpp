class Solution {
public:
    bool checkValidString(string s) {
        int leftmin=0,rightmin = 0;
        for(char c: s){
            if(c=='('){
                leftmin++;
                rightmin++;
            }else if(c==')'){
                leftmin--;
                rightmin--;
            }else{
                leftmin--;
                rightmin++;
            }

            leftmin = max(leftmin,0);
            if(rightmin<0)return false;
        }

        return leftmin==0;
    }
};
