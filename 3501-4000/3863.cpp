class Solution {
public:
  int minOperations(string s) {
    if (is_sorted(begin(s), end(s)))
        return 0;
    if (s.size() == 2)
        return -1;
    auto [min_p, max_p] = minmax_element(next(begin(s)), prev(end(s)));
    if (s[0] <= s.back() && (*min_p >= s[0] || *max_p <= s.back()))
        return 1;
    return s.back() < *min_p && s[0] > *max_p ? 3 : 2;
}
};
