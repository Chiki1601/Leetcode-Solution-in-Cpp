class Solution {
public:
    int countValidPrefixes(string s) {
        int ans = 0;
        int count0 = 0;
        int count1 = 0;
        for (char c: s) {
            if (c == '0') count0++;
            else count1++;
            if (abs(count1 - count0) <= 1) ans++;
        }
        return ans;
    }
};
