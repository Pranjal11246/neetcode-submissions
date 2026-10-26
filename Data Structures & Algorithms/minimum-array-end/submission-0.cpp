class Solution {
public:
    long long minEnd(int n, int x) {
        return x+pow(2,n-1);
    }
};