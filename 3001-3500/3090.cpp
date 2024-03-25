class Solution {
public:
  int maximumLengthSubstring(string s) {
    unordered_map<int, int> freq;
    int ans = 0;
    for(int i = 0, j = 0; i < s.size(); ++i){
        freq[s[i]]++;
        while(j < i  && freq[s[i]] > 2) freq[s[j++]]--; 
        ans = max(ans, i - j + 1);
    }
    return ans;
}
};
