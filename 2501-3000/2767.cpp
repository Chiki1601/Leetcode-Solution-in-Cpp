class Solution {
public:
    int solve(string& s, unordered_set<string>& st, int i){
        if(i == s.size()) return 0;
        int res = 100;
        for(int j = i+1; j <= s.size(); ++j){
            string t = s.substr(i, j-i);
            if(st.find(t) != st.end()) res = min(res, 1 + solve(s, st, j));
        }
        return res;
    }
    int minimumBeautifulSubstrings(string s) {
        unordered_set<string> st{"11110100001001", "110000110101", "1001110001", "1111101", "11001", "101", "1"};
        int ans = solve(s, st, 0);
        return (ans <= 15)?ans : -1;
    }
};
