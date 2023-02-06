class Solution {
public:
    long long minCost(vector<int>& A, vector<int>& B) {
        map<int, int> count;
        for (int a : A)
            ++count[a];
        for (int a : B)
            --count[a];
        vector<long long> swaps;
        long long res = 0, small = begin(count)->first;
        for (auto [a, v] : count) {
            if (v % 2) return -1;
            for (int i = 0; i < abs(v) / 2; ++i)
                swaps.push_back(a);
        }
        for (int i = 0; i < swaps.size() / 2; ++i)
            res += min(swaps[i], small * 2);
        return res;
    }
};
