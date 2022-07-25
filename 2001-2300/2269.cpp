class Solution {
public:
  int divisorSubstrings(int num, int k) {
    string s = to_string(num);
    int ans = 0;
    for (int i = 0; i <= s.length() - k; ++i) {
      const int t = stoi(s.substr(i, k));
      ans += t && (num % t == 0);
    }
    return ans;
  }
};
