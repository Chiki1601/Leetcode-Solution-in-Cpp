class Solution {
public:
   int maxPalindromes(string s, int k) {
    int n = s.size(), last = INT_MIN, ans = 0;
    vector<vector<int>> intervals;
    for (int center = 0; center < 2 * n; center++) {
        int left = center / 2;
        int right = left + center % 2;
        while (left >= 0 && right < n && s[left] == s[right]) {
            if (right + 1 - left >= k) {
                intervals.push_back({left, right + 1});
                break;
            }
            left--; right++;
        }
    }
    for (vector<int>& v: intervals) {
        if (v[0] >= last) {
            last = v[1];
            ans++;
        }
        else
            if (v[1] < last)
                last = v[1];
    }
    return ans;
}
};
