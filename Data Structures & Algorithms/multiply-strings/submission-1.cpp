class Solution {
public:
    string multiply(string num1, string num2) {
        long long n=stoi(num1),m=stoi(num2);
        return to_string(n*m);
    }
};
