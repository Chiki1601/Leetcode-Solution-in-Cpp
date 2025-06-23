class BinaryTrie {
    struct Node {
        int c[2];
        int cnt;
        bool leaf;
        Node() {
            c[0] = c[1] = 0;
            cnt = 0;
            leaf = false;
        }
    };

public:
    static vector<Node> T;
    int m;
    int root;

    BinaryTrie(int maxBits) : m(maxBits) {
        root = newNode();
    }

    int newNode() {
        T.push_back(Node());
        return (int)T.size() - 1;
    }

    void insert(long long num) {
        dfsInsert(root, num, m - 1);
    }

    void dfsInsert(int curr, long long num, int bit) {
        if (bit == -1) {
            T[curr].cnt = 1;
            T[curr].leaf = true;
            return;
        }
        int b = (num >> bit) & 1;
        if (!T[curr].c[b]) {
            T[curr].c[b] = newNode();
        }
        int nxt = T[curr].c[b];
        dfsInsert(nxt, num, bit - 1);
        int other = T[curr].c[b ^ 1];
        T[curr].cnt = T[nxt].cnt + (other ? T[other].cnt : 0);
    }

    void merge(BinaryTrie& other) {
        root = mergeRoot(root, other.root);
        other.root = 0;
    }

    int mergeRoot(int u, int v) {
        if (u == 0) return v;
        if (v == 0) return u;
        for (int b = 0; b < 2; b++) {
            int cu = T[u].c[b];
            int cv = T[v].c[b];
            if (!cu) {
                T[u].c[b] = cv;
            } else {
                T[u].c[b] = mergeRoot(cu, cv);
            }
        }
        int z = T[u].c[0], o = T[u].c[1];
        T[u].cnt = (z ? T[z].cnt : 0) + (o ? T[o].cnt : 0) + (T[u].leaf ? 1 : 0);
        return u;
    }

    long long kth_xor(int k) {
        long long res = 0;
        int curr = root;
        if (T[curr].cnt < k) return -1;
        for (int i = m - 1; i >= 0; i--) {
            int zero = T[curr].c[0];
            int one  = T[curr].c[1];
            int cnt0 = zero ? T[zero].cnt : 0;
            if (cnt0 >= k) {
                curr = zero;
            } else {
                k -= cnt0;
                if (one && T[one].cnt >= k) {
                    res |= (1LL << i);
                    curr = one;
                } else {
                    return -1;
                }
            }
            if (!curr) return -1;
        }
        return res;
    }
};

vector<BinaryTrie::Node> BinaryTrie::T;

class Solution {
public:
    vector<int> kthSmallest(vector<int>& par, vector<int>& vals, vector<vector<int>>& queries) {
        int n = par.size();
        vector<vector<int>> graph(n);
        for (int i = 1; i < n; i++) {
            graph[par[i]].push_back(i);
        }

        int q = queries.size();
        vector<vector<pair<int,int>>> Q(n);
        for (int i = 0; i < q; i++) {
            Q[queries[i][0]].push_back({queries[i][1], i});
        }

        BinaryTrie::T.clear();
        vector<int> prefix(vals);
        vector<int> ans(q);

        auto dfs = [&](auto& dfs, int node) -> BinaryTrie {
            BinaryTrie tree(17);
            for (int nei : graph[node]) {
                prefix[nei] ^= prefix[node];
                BinaryTrie childTree = dfs(dfs, nei);
                tree.merge(childTree);
            }
            tree.insert(prefix[node]);
            for (auto& [k, idx] : Q[node]) {
                ans[idx] = (int)tree.kth_xor(k);
            }
            return tree;
        };

        dfs(dfs, 0);
        return ans;
    }
};
