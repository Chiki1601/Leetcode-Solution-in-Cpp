#define ll long long
int longestSquareStreak(vector<int>& nums) {
    unordered_map<ll, int> m;
    // build map
    for(auto i : nums)
        ++m[i];
    sort(nums.begin(), nums.end());
    ll ans = -1;
    for(auto i : nums) {
        // break earlier
        if(!m.size())
            break;
        ll len = 0, now = i;
        while(m.count(now)) {
            m.erase(now);
            ++len;
            now *= now;
        }
        // valid ans
        if(len > 1)
            ans = max(ans, len);
    }
    return ans;
}
