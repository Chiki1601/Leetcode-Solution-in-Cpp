class Solution {
public:
   
vector<string> getWordsInLongestSubsequence(int n, vector<string>& words, vector<int>& groups) {
    vector<string> ans;
    int last = groups[0];
    ans.push_back(words[0]);
    for(int i = 1; i < words.size(); ++i){
        if(last != groups[i]){
            last = groups[i];
            ans.push_back(words[i]);
        }
    }
    return ans;
}
};
