class Solution {
public:
    int hammingWeight(uint32_t n) {
        int hamweight=0;
        while(n>0){
            hamweight+=n%2;
            n=n/2;
        }

        return hamweight;
    }
};
