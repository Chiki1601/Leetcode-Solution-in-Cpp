#pragma GCC optimize("Ofast")
#pragma GCC target("tune=native")
#include <vector>
using namespace std;

struct Node {
    vector<int> cnt;
    int prod;
    Node(int k) : cnt(k), prod(1) {}
};

class SegTree {
    int k, n, s;
    vector<Node> tree;
public:
    SegTree(const vector<int>& nums, int k) : k(k), n(nums.size()) {
        s = 1;
        while (s < n) s <<= 1;
        tree = vector<Node>(2 * s, Node(k));

        for (int i = 0; i < n; ++i) {
            int a_mod = nums[i] % k;
            tree[s + i].cnt[a_mod] = 1;
            tree[s + i].prod = a_mod;
        }

        for (int p = s - 1; p >= 1; --p) {
            tree[p] = merge(tree[2 * p], tree[2 * p + 1]);
        }
    }

    Node merge(const Node& l, const Node& r) {
        Node res(k);
        for (int i = 0; i < k; ++i) res.cnt[i] = l.cnt[i];
        for (int r_b = 0; r_b < k; ++r_b) {
            int c = r.cnt[r_b];
            if (c) {
                int r_ = (l.prod * r_b) % k;
                res.cnt[r_] += c;
            }
        }
        res.prod = (l.prod * r.prod) % k;
        return res;
    }

    void update(int idx, int val) {
        int pos = s + idx;
        int a_mod = val % k;
        fill(tree[pos].cnt.begin(), tree[pos].cnt.end(), 0);
        tree[pos].cnt[a_mod] = 1;
        tree[pos].prod = a_mod;

        for (pos >>= 1; pos >= 1; pos >>= 1) {
            tree[pos] = merge(tree[2 * pos], tree[2 * pos + 1]);
        }
    }

    Node query(int l, int r) {
        Node cnt_l(k), cnt_r(k);
        cnt_l.prod = cnt_r.prod = 1;
        l += s;
        r += s;
        while (l < r) {
            if (l & 1) {
                cnt_l = merge(cnt_l, tree[l++]);
            }
            if (r & 1) {
                cnt_r = merge(tree[--r], cnt_r);
            }
            l >>= 1;
            r >>= 1;
        }
        return merge(cnt_l, cnt_r);
    }
};

class Solution {
public:
    vector<int> resultArray(vector<int>& nums, int k, vector<vector<int>>& queries) {
        SegTree st(nums, k);
        vector<int> res;
        for (auto& q : queries) {
            int idx = q[0], val = q[1], start = q[2], x = q[3];
            st.update(idx, val);
            Node result = st.query(start, nums.size());
            res.push_back(result.cnt[x]);
        }
        return res;
    }
};
