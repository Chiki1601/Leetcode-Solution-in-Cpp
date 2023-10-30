#define N       100005
#define ll      long long
#define hell    1000000007

class Solution {
public:
    
    ll int a[N];
    ll int seg[4*N], segsq[4*N], lazy[4*N];

    // Build the segment tree.
    void build(int node, ll int start, ll int end) {
        if (start == end) {
            seg[node] = a[start];
            segsq[node] = (a[start] * a[start]) % hell;
            return;
        }
        ll int mid = (start + end) >> 1;
        build(node << 1, start, mid);
        build(node << 1 | 1, mid + 1, end);
        seg[node] = (seg[node << 1] + seg[node << 1 | 1]) % hell;
        segsq[node] = (segsq[node << 1] + segsq[node << 1 | 1]) % hell;
    }

    // Update the segment tree and handle lazy propagation.
    void update(int node, ll int start, ll int end, int l, int r, int val) {
        if (lazy[node] != 0) {
            segsq[node] += ((end - start + 1) * (lazy[node] * lazy[node]) % hell) % hell + (2 * lazy[node] * seg[node]) % hell;
            segsq[node] %= hell;
            seg[node] += ((end - start + 1) * lazy[node]) % hell;
            seg[node] %= hell;
            if (start != end) {
                lazy[node << 1] += lazy[node];
                lazy[node << 1 | 1] += lazy[node];
            }
            lazy[node] = 0;
        }
        if (start > end || start > r || end < l) return;
        if (l <= start && end <= r) {
            segsq[node] += ((end - start + 1) * (val * val) % hell) % hell + (2 * val * seg[node]) % hell;
            segsq[node] %= hell;
            seg[node] += ((end - start + 1) * val) % hell;
            seg[node] %= hell;
            if (start != end) {
                lazy[node << 1] += val;
                lazy[node << 1 | 1] += val;
            }
            return;
        }
        ll int mid = (start + end) >> 1;
        update(node << 1, start, mid, l, r, val);
        update(node << 1 | 1, mid + 1, end, l, r, val);
        seg[node] = (seg[node << 1] + seg[node << 1 | 1]) % hell;
        segsq[node] = (segsq[node << 1] + segsq[node << 1 | 1]) % hell;
    }

    // Main function to find the sum of counts.
    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        
        // Initialize the array 'a' with 0 values.
        for (int i = 1; i <= n; i++) {
            a[i] = 0;
        }
        
        // Build the segment tree.
        build(1, 1, n);
        
        // Use a map to store the last seen index of each number.
        unordered_map<int, int> prev_seen_at;
        
        ll int ans = 0;
        
        for (int i = n - 1; i >= 0; i--) {
            if (prev_seen_at.find(nums[i]) == prev_seen_at.end()) {
                update(1, 1, n, i + 1, n, 1);
            }
            else {
                update(1, 1, n, i + 1, prev_seen_at[nums[i]] - 1, 1);
            }
            
            prev_seen_at[nums[i]] = i + 1;
            
            ans = (ans + segsq[1]) % hell;
        }
        
        return ans;
    }
};
