class Solution {
public:
    int func(int idx, string &s, set<string> &st, vector<int>& dp)
    {
        if (idx == s.size())
            return 0;
        if (dp[idx] != -1)
            return dp[idx];
        int res = 1e9;
        for (int j = idx; j < s.size(); ++j)
        {
            string str = s.substr(idx, j - idx + 1);
            if (st.find(str) != st.end())
            {
                res = min(res, 0 + func(j + 1, s, st, dp));
            }
            else
                res = min(res, j - idx + 1 + func(j + 1, s, st, dp));
        }
        return dp[idx] = res;
    }
    int minExtraChar(string s, vector<string>& dictionary) {
        vector<int> dp(s.size() + 1, -1);
        set<string> st(dictionary.begin(), dictionary.end());
        return func(0, s, st, dp);
    }
};
