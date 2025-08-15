class Solution {
public:
   long long maxTotal(vector<int>& value, vector<int>& limit) {
    long long res = 0;
    unordered_map<int, vector<int>> m;
    for (int i = 0; i < value.size(); ++i)
        m[limit[i]].push_back(value[i]);
    for (auto& [lim, v] : m) {
        if (v.size() > lim)
            nth_element(begin(v), begin(v) + lim, end(v), greater<>{});
        res += accumulate(begin(v), begin(v) + min((int)v.size(), lim), 0ll);
    }
    return res;
}
};
