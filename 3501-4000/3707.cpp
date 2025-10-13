class Solution {
public:
    bool scoreBalance(string s) {
        int c = 0;
        for (auto i : s) c += i - 'a' + 1;
        int x = 0;
        for (auto i : s) {
            x += i - 'a' + 1;
            if (x * 2 == c) return true;
        }
        return false;
    }
};
