class Solution {
public:
    int maxDistinct(string s) {
        int hash[26] = {0}, ans = 0;
        for(char c : s) hash[c - 'a']++;
        for(int i = 0; i < 26; i++) {
            if(hash[i] != 0) ans++;
        }
        return ans;
    }
};
