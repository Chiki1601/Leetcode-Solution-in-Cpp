class Solution {
public:
    string processStr(std::string s) {
        string res = "";
        for (char c : s) {
            if (c != '*' && c != '#' && c != '%') {
                res += c;
            } else if (c == '#') {
                res += res;
            } else if (c == '%') {
                reverse(res.begin(), res.end());
            } else {
                if (!res.empty()) res.pop_back();
            }
        }
        return res;
    }
};
