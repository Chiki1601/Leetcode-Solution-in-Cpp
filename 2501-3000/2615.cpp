typedef long long ll;

class Solution {
public:
    vector<long long> distance(vector<int>& v) {
        unordered_map<int,vector<ll>> mps;
        unordered_map<int,vector<int>> mi;
        int n = v.size();
        for(int i = 0; i < n; i += 1) {
            int x = v[i];
            if(!mps.count(x)) mps[x].push_back(0);
            mps[x].push_back(mps[x].back() + (ll)i + 1);
            mi[x].push_back(i);
        }
        vector<ll> ans(n);
        for(int i = 0; i < n; i += 1) {
            int idx = lower_bound(mi[v[i]].begin(),mi[v[i]].end(),i + 1) - mi[v[i]].begin();
            ll left = idx, right = mi[v[i]].size() - idx;
            ans[i] = left*(i + 1LL) - mps[v[i]][left - 1] + mps[v[i]].back() - mps[v[i]][left] - (right + 1LL) * (i + 1LL);
        }
        return ans;
    }
};
