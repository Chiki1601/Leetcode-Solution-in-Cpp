class Solution {
public:
    vector<int> psum{0};
    long long minCost(int l, int r, int encCost, int flatCost) {
        long long cnt = psum[r] - psum[l], sz = r - l;
        long long cost = cnt ? cnt * sz * encCost : flatCost;
        if (cnt && sz % 2 == 0) {
            cost = min(cost, 
                minCost(l, l + sz / 2, encCost, flatCost) +
                minCost(l + sz / 2, r, encCost, flatCost));
        }
        return cost;
    }
    long long minCost(string s, int encCost, int flatCost) {
        for (auto ch : s)
            psum.push_back(psum.back() + (ch == '1'));
        return minCost(0, s.size(), encCost, flatCost);
    }
};
