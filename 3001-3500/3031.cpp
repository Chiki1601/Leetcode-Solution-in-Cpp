class Solution {
public:
  int minimumTimeToInitialState(string word, int k) {
    auto z = z_function(word);
    for (int i = k, n = word.size(); i < n; i += k)
        if (z[i] == n - i)
            return i / k;
    return (word.size() + k - 1) / k;
}
};
