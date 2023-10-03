#define ll long long

class Sieve {
public:
    vector<int> sieve; // isPrime or not
    int n;
    
    Sieve() {
        n = 0;
    }

    void init(int n) {
        if(this->n > 0) {
            return;
        }
        this->n = n;
        sieve = vector<int>(n + 1, true); // is prime or not
        sieve[0] = sieve[1] = false;
        for (int i = 2; i <= n; i++) {
            if (sieve[i]) {
                for (int j = i + i; j <= n; j += i) {
                    sieve[j] = false;
                }
            }
        }
    }
};

class DSU {
public:
    vector<int> parent;
    vector<int> rank;
    vector<int> size;

    DSU(int n) {
        rank = vector<int>(n);
        parent = vector<int>(n);
        size = vector<int>(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            rank[i] = 0;
            size[i] = 1;
        }
    }

    int findPar(int node) {
        if (parent[node] == node) return node;
        return parent[node] = findPar(parent[node]);
    }

    void makeUnion(int u, int v) {
        u = findPar(u);
        v = findPar(v);

        if (rank[u] < rank[v]) {
            parent[u] = v;
            size[v] += size[u];
        } else if (rank[u] > rank[v]) {
            parent[v] = u;
            size[u] += size[v];
        } else {
            rank[u]++;
            parent[v] = u;
            size[u] += size[v];
        }
    }

    bool sameSet(int u, int v) {
        u = findPar(u);
        v = findPar(v);

        if (u == v) return true;
        return false;
    }
};

// Global
Sieve s;

class Solution {
public:
    
    vector<vector<int>> adj;
    
    bool isPrime(int num) {
        return s.sieve[num];
    }

    long long countPaths(int n, vector<vector<int>>& edges) {
        s.init(1e5 + 10);
        DSU dsu(n);
        adj = vector<vector<int>>(n);
        for(auto edge: edges) {
            int u = edge[0], v = edge[1];
            u--, v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
            if(isPrime(u+1) || isPrime(v+1)) continue;
            dsu.makeUnion(u, v);
        }
        
        ll res = 0;
        
        for(int i = 0; i < n; i++) {
            if(isPrime(i+1) == false) continue;
            int node = i;
            ll currRes = 0;
            vector<ll> val;
            for(auto nbr: adj[node]) {
                if(isPrime(nbr+1)) continue;
                int sz = dsu.size[dsu.findPar(nbr)];
                res += sz;
                if(sz) val.push_back(sz);
            }
            if(val.size() == 0) continue;
            
            ll left = val[0];
            for(int j = 1; j < val.size(); j++) {
                res += val[j] * left;
                left += val[j];
            }
        }
        
        return res;
    }
};
