class UnionFind {
    vector<int> id, size;
    int cnt;
public:
    UnionFind(int n) : id(n), size(n, 1), cnt(n) {
        iota(begin(id), end(id), 0);
    }
    int find(int a) {
        return id[a] == a ? a : (id[a] = find(id[a]));
    }
    void connect(int a, int b) {
        int x = find(a), y = find(b);
        if (x == y) return;
        id[x] = y;
        size[y] += size[x];
        --cnt;
    }
    int getSize(int a) {
        return size[find(a)];
    }
    int getCount() { return cnt; }
};
class Solution {
public:
    vector<int> groupStrings(vector<string>& A) {
        int N = A.size();
        UnionFind uf(N);
        unordered_map<int, int> m; // map from hash to index
        m.reserve(N);
        for (int i = 0; i < N; ++i) {
            int h = 0;
            for (char c : A[i]) h |= 1 << (c - 'a'); // `h` is the bitmask representation of `A[i]`
            for (int j = 0; j < 26; ++j) {
                if (h >> j & 1) { // if `h`'s j-th bit is 1
                    int del = h ^ (1 << j); // `del` is the bitmask after deleting the `j`-th bit
                    if (m.count(del)) uf.connect(i, m[del]); // Connect `A[i]` with its deletion variant
                    for (int k = 0; k < 26; ++k) { // we replace `j`-th bit with `k`-th bit
                        int rep = del | (1 << k); // `rep` is the bitmask after replacing `j`-th bit with `k`-th bit.
                        if (rep != del && m.count(rep)) uf.connect(i, m[rep]);
                    }
                } else {
                    int add = h | (1 << j); // `add` is the bitmask after adding `j`-th bit
                    if (m.count(add)) uf.connect(i, m[add]);
                }
            }
            m[h] = i;
        }
        int mx = 1;
        for (int i = 0; i < N; ++ i) mx = max(mx, uf.getSize(i));
        return {uf.getCount(), mx};
    }
};
