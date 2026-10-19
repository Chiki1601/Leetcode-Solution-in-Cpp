class Solution {
public:
    int minSelection(vector<vector<int>>& a, vector<vector<int>>& t) {
        int n = a.size(), m = t.size();
        sort(a.begin(), a.end());
        sort(t.begin(), t.end());

        int i = 0, j = 0, maxi = -1, cur = t[j][0], ans = 0;
        while(j < m) {
            int pmax = maxi;
            while(i < n && a[i][0] <= cur) {
                maxi = max(maxi, a[i][1]);
                i++;
            }
            if(pmax == maxi) return -1;
            ++ans;

            while(j < m && t[j][1] <= maxi) ++j;
            if(j == m) return ans;

            if(maxi < t[j][0]) cur = t[j][0];
            else cur = maxi;
        }
        return ans;
    }
};
