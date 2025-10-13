class Solution {
public:
#define ll long long
    vector<vector<int>> adj;
    vector<int> arr;
    ll ans;

    int remove_dupli(int num) {
        int ans = 1;

        for (ll i = 2; i * i <= num; i++) {
            if (num % i == 0) {
                int cnt = 0;
                while (num % i == 0) {
                    num = num / i;
                    cnt++;
                }
                if (cnt & 1) {
                    ans = ans * i;
                }
            }
        }

        if (num > 1) {
            ans = ans * num;
        }
        return ans;
    }

    void merge(map<int, ll>& curr, map<int, ll> copy) {

        if (curr.size() < copy.size()) {
            swap(curr, copy);
        }

        for (auto it : copy) {
            curr[it.first] += it.second;
        }
    }

    map<int, ll> dfs(int node, int par) {

        map<int, ll> curr;
        for (auto it : adj[node]) {
            if (it == par) {
                continue;
            }
            merge(curr, dfs(it, node));
        }

        int num = remove_dupli(arr[node]);
        ans += curr[num];
        curr[num]++;
        return curr;
    }

    long long sumOfAncestors(int n, vector<vector<int>>& edges,
                             vector<int>& nums) {

        adj.resize(n);
        for (auto it : edges) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        this->ans = 0;
        this->arr = nums;

        dfs(0, -1);

        return ans;
    }
};
