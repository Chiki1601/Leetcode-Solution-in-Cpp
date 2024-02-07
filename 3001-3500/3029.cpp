class Solution {
public:
    bool isEqual(string &word, string &target){
        int n = word.size();
        for(int i=0;i<n;i++){
            if(target[i]!='*' && word[i]!=target[i]){
                return false;
            }
        }
        return true;
    }
    int minimumTimeToInitialState(string word, int k) {
        string copy = word;
        int count = 0;
        do{
            copy = copy.substr(k) + string(k, '*');
            count++;
        } while(!isEqual(word, copy));
        return count;
    }
};
