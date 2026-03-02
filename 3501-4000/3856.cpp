class Solution {
public:
    // brute force
    bool check(int ind, string& s) {
        for (int i = ind; i < s.length(); i++) {
            char ch = s[i];
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
                continue;
            else
                return false;
        }
        return true;
    }
    string trimTrailingVowels(string s) {
        for (int i = 0; i < s.length(); i++) {
            bool canRemove = check(i, s);
            if (canRemove)
                return s.substr(0, i);
        }
        return s;
    }
    // better
    string trimTrailingVowels(string s) {
        stack<char> st;
        for (auto it : s)
            st.push(it);
        while (!st.empty()) {
            char ch = st.top();
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
                st.pop();
            else
                break;
        }
        string ans = "";
        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
    // optimal
    string trimTrailingVowels(string s) {
        int lastInd = s.length() - 1;
        while (lastInd >= 0) {
            char ch = s[lastInd];
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
                lastInd--;
            else
                break;
        }
        int lenOfAns = lastInd + 1;
        return s.substr(0, lenOfAns);
    }
};
