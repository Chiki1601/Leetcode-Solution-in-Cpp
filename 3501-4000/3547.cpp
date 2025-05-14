class Solution {
public:
    using ll = long long;
    vector<bool> v; 

    bool dfs(int n, int p, vector<vector<int>> &G, int &cnt, int a) {
        v[n] = true;
        cnt++;
        for (int x : G[n]) {
            if (!v[x]) {
                if (dfs(x, n, G, cnt, a)) return true;
            } else if (x != p) return true;
        }
        return false; 
    }
    long long maxScore(int n, vector<vector<int>>& edges) { 
        int val = n;
        vector<vector<int>> G(n + 1);
        for (auto &it : edges) {
            G[it[0]].push_back(it[1]);
            G[it[1]].push_back(it[0]); 
        }

        v = vector<bool>(n + 1, false);
        vector<pair<int, int>> c, nc; // cyclic and noncyclic -> {size, startnode}

        for (int i = 0; i < n; i++) {
            if (!v[i]) {
                int cnt = 0;
                if (dfs(i, -1, G, cnt, i)) {
                    c.push_back({cnt, i});
                } else {
                    nc.push_back({cnt, i});
                }
            }
        }

        // sorting in decending order
        sort(c.rbegin(), c.rend());
        sort(nc.rbegin(), nc.rend());

        ll anss = 0;
        v = vector<bool>(n + 1, false);
        val = n;

// first priority cyclic component
        for (auto &i : c) {
            int s = i.first; // size
            vector<ll> a(s);
            int st = val - s + 1, e = val; 
            int j = 0;

            for( j = 0; j < s / 2; j++){
                a[j] = st++, a[s - j - 1] = st++;
            }

            if(s % 2)
                a[j] = st; 

            for(int i = 1; i < s; i++)
                anss += (a[i] * a[i - 1]);
            anss += a.back() * a.front(); // cycle thats why
            val = val - s;
        }
// Acyclic
        for (auto &i : nc) {
            int s = i.first;
            vector<ll> a(s);
            int st = val - s + 1, e = val;

            int j = 0;
            for( j = 0; j < s / 2; j++){
                a[j] = st++, a[s - j - 1] = st++;
            }
            if(s % 2)
                a[j] = st;

            cout << endl; 
// theree is no cycle
            for(int i = 1; i < s; i++)
                anss += (a[i] * a[i - 1]);

            val = val - s;
        } 
        return anss;
    }
};
