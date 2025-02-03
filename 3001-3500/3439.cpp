class Solution {
public:
    int ansTime(int eventTime, int k, vector<int>& st, vector<int>& et) {
        int n = st.size();
        vector<int> gaps(n + 1);

        // Calculate the first and last gap separately
        gaps[0] = st[0];  // Free time before the first meeting
        gaps[n] = eventTime - et[n - 1];  // Free time after the last meeting

        // Compute gaps between meetings
        for(int i = 1; i < n; i++){
            gaps[i] = st[i] - et[i - 1];
        }

        // Compute prefix sum for efficient range sum calculation
        vector<int> pref(n + 2, 0);
        for(int i = 1; i <= n + 1; i++){
            pref[i] = pref[i - 1] + gaps[i - 1];
        }

        int ans = 0;
        for(int i = k + 1; i <= n + 1; i++){
            ans = max(ans, pref[i] - pref[i - (k + 1)]);
        }

        return ans;
    }
};
