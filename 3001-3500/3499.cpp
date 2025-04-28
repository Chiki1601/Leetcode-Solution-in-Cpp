class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        string t = "1" + s + "1";

        // format : 1 0....0 1.......1 0........0 1

        int n = t.size(), i = 0, one = 0, zero = 0;
        int curr = 0, prev = 0;
        
        while (i < n && t[i] == '1') one++, i++;
        while (i < n && t[i] == '0') prev++, i++;
        
        while (i < n) {
            while (i < n && t[i] == '1') one++, i++;
            if (i == n) break;
            while (i < n && t[i] == '0') curr++, i++;
            zero = max(zero, prev + curr);
            prev = curr;
            curr = 0;
        }

        return one + zero - 2;
    }
};
