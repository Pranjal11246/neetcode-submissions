class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if(find(wordList.begin(),wordList.end(),endWord)==wordList.end())return 0;

        vector<int> checkidx;

        for(int i=0;i<beginWord.size();i++){
            if(endWord[i]!=beginWord[i])checkidx.push_back(i);
        }

        if(checkidx.size()==0)return 0;
        int counter=0;

        for(int i=0;i<wordList.size();i++){
            for(int j:checkidx){
                if(wordList[i][j]==endWord[j] && wordList[i][j]!=beginWord[j]){
                    beginWord[j] = wordList[i][j];
                    break;
                }
            }
            counter++;
            if(beginWord==endWord)break;
        }
        return counter+1;
    }
};
