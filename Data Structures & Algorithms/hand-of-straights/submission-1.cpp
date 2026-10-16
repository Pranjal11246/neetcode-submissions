class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        map<int,int> freq;
        //sort(hand.begin(),hand.end());
        int n = hand.size();
        for(int i=0;i<n;i++){
            freq[hand[i]]++;
        }

        for(int i=0;i<n;i++){
            if(freq[hand[i]]>0){
                int newmax = hand[i] + groupSize-1;
                for(int j = hand[i];j<=newmax;j++){
                    if(freq[j]<1)return false;
                    freq[j]--;
                }
            }
        }

        return true;
    }
};
