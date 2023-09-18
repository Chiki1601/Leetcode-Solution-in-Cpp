class Solution {
public:
    // As, len is (5 * 10 ^ 4) and k is 100, then just
    // Bruteforce over pairs for every possible division in k
    // means for a pair {x, y}, we need to find {a, b} such that x ^ a + y ^ b == k
    // then for every partition in k
    // 1. x ^ a == 0 and y ^ b == k, or we can say x ^ 0 == a and y ^ k == b thus check whether {a, b} exists
    // 2. x ^ a == 1 and y ^ b == k - 1, or we can say x ^ 1 == a and y ^ (k - 1) == b thus check {a, b} exists
    // .
    // .
    // .
    // k. x ^ a == k and y ^ b == 0, or we can say x ^ k == a and y ^ 0 == b thus check whether {a, b} exists
    int countPairs(vector<vector<int>>& c, int k) {
        map<pair<int, int>, int> f;
        long long ans = 0;
        for(auto i: c) {
            for(int j = 0; j <= k; j++) {
                int x = j ^ i[0];
                int y = (k - j) ^ i[1];
                if(f.find({x, y}) != f.end()) {
                    ans += f[{x, y}];
                }
            }
            f[{i[0], i[1]}]++;
        }
        return ans;
    }
};
