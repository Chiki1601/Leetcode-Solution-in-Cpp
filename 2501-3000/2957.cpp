class Solution {
public:
   int removeAlmostEqualCharacters(string word) {
    int ans = 0;
    for(int i = 1; i < word.size(); i ++){
        if(abs(word[i] - word[i-1]) <= 1){ ans++; i++; }
    }
    return ans;
}
};
