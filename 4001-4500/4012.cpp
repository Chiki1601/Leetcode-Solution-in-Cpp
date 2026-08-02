class Solution {
public:
    vector<int> countTasks(vector<int>& tasks, vector<int>& shifts) {
        int n = tasks.size();
        vector<long long> pref(n, 0);
        long long p = 0;
        for (int i = 0; i < n; i++) {
            pref[i] = p + tasks[i];
            p = pref[i];
        }
        vector<int> ans(shifts.size(), 0);
        long long prev = 0;
        for (int i = 0; i < shifts.size(); i++) {
            long long touse = shifts[i] + prev;

            if (shifts[i] >= pref[n - 1]) {
                ans[i] = 0;
                prev = 0;
                continue;
            }

            auto it = upper_bound(pref.begin(), pref.end(), touse);

            int k = 0;

            if (it != pref.end()) {
                int l = it - pref.begin();
                k = n - l;
            }
            ans[i] = k;
            if (touse >= pref[n - 1]) {
                prev = 0;
            } else {
                prev += shifts[i];
            }
        }
        return ans;
    }
};
