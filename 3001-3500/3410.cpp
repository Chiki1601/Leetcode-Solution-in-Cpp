using ll = long long;

class node
{
public:
    ll prefsum = 0, suffsum = 0, maxi = LLONG_MIN, tot = 0;
    node() {}
    node(const ll &val)
    {
        prefsum = suffsum = maxi = tot = val;
    }
};

class SegmentTree
{
public:
    vector<node> seg;
    SegmentTree(const ll &n)
    {
        seg.resize(4 * n + 1);
    }
    node combine(const node &a, const node &b)
    {
        node ans;
        ans.tot = a.tot + b.tot;
        ans.prefsum = max(a.prefsum, a.tot + b.prefsum);
        ans.suffsum = max(b.suffsum, b.tot + a.suffsum);
        ans.maxi = max({a.maxi, b.maxi, a.suffsum + b.prefsum});
        return ans;
    }

    void build(ll root, ll l, ll r, const vector<int> &nums)
    {
        if (l == r)
        {
            seg[root] = node(nums[l]);
            return;
        }
        ll m = l + (r - l) / 2;
        build(2 * root + 1, l, m, nums);
        build(2 * root + 2, m + 1, r, nums);
        seg[root] = combine(seg[2 * root + 1], seg[2 * root + 2]);
    }

    void update(ll root, ll l, ll r, ll pos, ll val)
    {
        if (pos < l || pos > r)
            return;
        if (l == r)
        {
            seg[root] = node(val);
            return;
        }
        ll m = l + (r - l) / 2;
        update(2 * root + 1, l, m, pos, val);
        update(2 * root + 2, m + 1, r, pos, val);
        seg[root] = combine(seg[2 * root + 1], seg[2 * root + 2]);
    }

    node query(ll root, ll l, ll r, ll ql, ll qr)
    {
        if (ql > r || qr < l)
            return node(0);
        if (ql <= l && r <= qr)
            return seg[root];
        ll m = l + (r - l) / 2;
        return combine(query(2 * root + 1, l, m, ql, qr), query(2 * root + 2, m + 1, r, ql, qr));
    }
};

class Solution
{
public:
    long long maxSubarraySum(vector<int> &nums)
    {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        map<int, vector<int>> mp;
        ll n = nums.size(), ans = LLONG_MIN, maxi = LLONG_MIN;
        SegmentTree segmentTree(n);
        segmentTree.build(0, 0, n - 1, nums);
        ll sum = 0, cntn = 0;

        for (int i = 0; i < n; i++)
        {
            mp[nums[i]].push_back(i);
            maxi = max(maxi, (ll)nums[i]);
            sum = sum + (ll)nums[i];
            if (nums[i] < 0)
                cntn++;
        }

        if (cntn == 0)
            return sum;
        if (maxi < 0)
            return maxi;

        for (auto &it : mp)
        {
            vector<int> &temp = it.second;
            for (int i = 0; i < (int)temp.size(); i++)
            {
                segmentTree.update(0, 0, n - 1, temp[i], 0);
            }
            ans = max(ans, segmentTree.seg[0].maxi);
            for (int i = 0; i < (int)temp.size(); i++)
            {
                segmentTree.update(0, 0, n - 1, temp[i], it.first);
            }
        }

        return ans;
    }
};
