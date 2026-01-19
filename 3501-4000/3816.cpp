class Solution {
public:
    string lexSmallestAfterDeletion(string s) {
        string ans;
        stack<char> st;
        int comingfreq[26] = {0};
        int currfreq[26] = {0};

        for (char ele : s) {
            comingfreq[ele - 'a']++;
        }

        for (char ele : s) {
            comingfreq[ele - 'a']--;

            while (!st.empty() &&
                   st.top() > ele &&
                   (comingfreq[st.top() - 'a'] > 0 ||
                    currfreq[st.top() - 'a'] > 1)) {

                currfreq[st.top() - 'a']--;
                st.pop();
            }

            st.push(ele);
            currfreq[ele - 'a']++;
        }

        // final cleanup (VERY IMPORTANT)
        while (!st.empty() && currfreq[st.top() - 'a'] > 1) {
            currfreq[st.top() - 'a']--;
            st.pop();
        }

        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};
