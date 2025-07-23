#include <vector>
#include <iostream>
using namespace std;

class SegmentTree {
    int n;
    vector<vector<int>> tree;

    int getDepth(long long x) {
        int d = 0;
        while (x > 1) {
            x = __builtin_popcountll(x); // For long long
            d++;
        }
        return d;
    }

    void build(int l, int r, int node, const vector<long long>& nums) {
        if (l == r) {
            int depth = getDepth(nums[l]);
            tree[node][depth] = 1;
            return;
        }
        int mid = (l + r) / 2;
        build(l, mid, node * 2, nums);
        build(mid + 1, r, node * 2 + 1, nums);
        for (int i = 0; i < 6; ++i)
            tree[node][i] = tree[node * 2][i] + tree[node * 2 + 1][i];
    }

    void update(int idx, long long val, int l, int r, int node) {
        if (l == r) {
            tree[node] = vector<int>(6, 0);
            int depth = getDepth(val);
            tree[node][depth] = 1;
            return;
        }
        int mid = (l + r) / 2;
        if (idx <= mid)
            update(idx, val, l, mid, node * 2);
        else
            update(idx, val, mid + 1, r, node * 2 + 1);
        for (int i = 0; i < 6; ++i)
            tree[node][i] = tree[node * 2][i] + tree[node * 2 + 1][i];
    }

    int query(int ql, int qr, int l, int r, int node, int k) {
        if (qr < l || r < ql)
            return 0;
        if (ql <= l && r <= qr)
            return tree[node][k];
        int mid = (l + r) / 2;
        return query(ql, qr, l, mid, node * 2, k) +
               query(ql, qr, mid + 1, r, node * 2 + 1, k);
    }

public:
    SegmentTree(const vector<long long>& nums) {
        n = nums.size();
        tree.assign(4 * n, vector<int>(6, 0));
        build(0, n - 1, 1, nums);
    }

    void update(int idx, long long val) {
        update(idx, val, 0, n - 1, 1);
    }

    int getCount(int l, int r, int k) {
        return query(l, r, 0, n - 1, 1, k);
    }

    int size() const {
        return n;
    }
};

class Solution {
public:
    vector<int> popcountDepth(vector<long long>& nums, vector<vector<long long>>& queries) {
        SegmentTree tree(nums);
        vector<int> res;
        for (auto& q : queries) {
            if (q[0] == 1) {
                int l = q[1], r = q[2], k = q[3];
                res.push_back(tree.getCount(l, r, k));
            } else {
                int idx = q[1];
                long long val = q[2];
                tree.update(idx, val);
            }
        }
        return res;
    }
};
