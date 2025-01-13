#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")

class Solution {
public:
    struct SegmentTree {
        vector<long long> tree, lz;
        int n;

        SegmentTree(int n) : n(n) {
            tree.assign(4 * n, 0);
            lz.assign(4 * n, 0);
        }

        void push(int v, int tl, int tr, int tm) {
            if (tl != tr) {
                tree[v * 2] = lz[v] * (tm - tl + 1);
                tree[v * 2 + 1] = lz[v] * (tr - tm);
                lz[v * 2] = lz[v];
                lz[v * 2 + 1] = lz[v];
            }
            lz[v] = 0;
        }

        void update(int v, int tl, int tr, int l, int r, long long add) {
            if (tl > r || tr < l)
                return;
            int tm = (tl + tr) / 2;
            if (lz[v] != 0)
                push(v, tl, tr, tm);
            if (l <= tl && tr <= r) {
                tree[v] = add * (tr - tl + 1);
                lz[v] = add;
                return;
            }
            update(v * 2, tl, tm, l, r, add);
            update(v * 2 + 1, tm + 1, tr, l, r, add);
            tree[v] = tree[v * 2] + tree[v * 2 + 1];
        }

        long long get(int v, int tl, int tr, int l, int r) {
            if (tl > r || tr < l)
                return 0ll;
            int tm = (tl + tr) / 2;
            if (lz[v] != 0)
                push(v, tl, tr, tm);
            if (l <= tl && tr <= r)
                return tree[v];
            return get(v * 2, tl, tm, l, r) + get(v * 2 + 1, tm + 1, tr, l, r);
        }
    };

    long long countNonDecreasingSubarrays(vector<int>& a, int k) {
        long long res = 0;
        long long n = a.size();
        vector<long long> pref(n + 1);
        for (int i = 1; i <= n; ++i) 
            pref[i] = pref[i - 1] + a[i - 1];
        
        SegmentTree st(n);
        st.update(1, 1, n, n, n, a[n - 1]);
        stack<int> q;
        q.push(n);
        for (int i = n - 1; i >= 1; --i) {
            int l, r, pos, found;
            int last = i;
            while (!q.empty() && a[q.top() - 1] <= a[i - 1]) {
                a[q.top() - 1] = a[i - 1];
                last = q.top();
                q.pop();
            }
            if (q.empty()) last = n;
            q.push(last);
            st.update(1, 1, n, i, last, a[i - 1]);
            l = i, r = n, found = n;
            if (st.get(1, 1, n, i, n) - pref[n] + pref[i - 1] <= k) continue;
            while (l <= r) {
                int mid = (l + r) >> 1;
                long long sum = st.get(1, 1, n, last + 1, mid)
                                + 1ll * (min(mid, last) - i + 1) * a[i - 1];
                if (sum - pref[mid] + pref[i - 1] <= k) {
                    l = mid + 1;
                } else {
                    found = mid;
                    r = mid - 1;
                }
            }
            res += n - found + 1;
        }
        return n * (n + 1) / 2 - res;
    }
};
