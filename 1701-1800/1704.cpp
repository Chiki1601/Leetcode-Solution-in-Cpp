class Solution {
    int count(string s) {
        int cnt = 0;
        for (char c : s) {
            c = tolower(c);
            cnt += c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
        }
        return cnt;
    }
public:
    bool halvesAreAlike(string s) {
        return count(s.substr(0, s.size() / 2)) == count(s.substr(s.size() / 2));
    }
};
