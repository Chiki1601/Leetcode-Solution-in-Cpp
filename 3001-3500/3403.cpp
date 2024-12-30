class Solution {
public:
  string answerString(string word, int numFriends) {
    if(numFriends == 1) return word;
    string ans = "";
    for(int i = 0, len = word.size() - (numFriends - 1); i < word.size(); ++i){
        string t = word.substr(i, (word.size() - i) < len?word.size() - i: len);
        if(ans.compare(t) < 0) ans = t;
    }
    return ans;
}
};
