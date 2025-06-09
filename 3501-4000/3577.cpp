class Solution {
public:
    int MOD = 1e9 + 7;
    
    int countPermutations(vector<int>& comp) {
        int n = comp.size();
        long long ans = 1;

        for (int i = 1; i < n; i++) {
            if (comp[i] <= comp[0]) return 0;
            ans *= i;
            ans %= MOD;
        }

        return ans;
    }
};
