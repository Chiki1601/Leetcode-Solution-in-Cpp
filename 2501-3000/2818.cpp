class Solution {
public:
    const int MOD = 1000000007;

    int maximumScore(vector<int>& nums, int k) {
        int n = nums.size();

        int upper = *max_element(nums.begin(), nums.end()) + 1;

        vector<bool> prime(upper, true);
        prime[0] = prime[1] = false;
        vector<int> primeScore(upper, 0);
        for (int i = 2; i < upper; i++) {
            if (prime[i]) {
                for (int j = i; j < upper; j += i) {
                    primeScore[j]++;
                    prime[j] = false;
                }
            }
        }

        vector<int> nextGreaterElement(n, n);
        stack<int> s;
        for (int i = n - 1; i >= 0; i--) {
            while (!s.empty() && primeScore[nums[i]] >= primeScore[nums[s.top()]]) {
                s.pop();
            }
            nextGreaterElement[i] = s.empty() ? n : s.top();
            s.push(i);
        }

        vector<int> prevGreaterOrEqualElement(n, -1);
        s = stack<int>();
        for (int i = 0; i < n; i++) {
            while (!s.empty() && primeScore[nums[i]] > primeScore[nums[s.top()]]) {
                s.pop();
            }
            prevGreaterOrEqualElement[i] = s.empty() ? -1 : s.top();
            s.push(i);
        }

        int res = 1;
        vector<pair<int, int>> tuples(n);
        for (int i = 0; i < n; i++) {
            tuples[i].first = nums[i];
            tuples[i].second = i;
        }
        sort(tuples.rbegin(), tuples.rend());
        for (const auto& [num, i] : tuples) {
            int operations = min((i - prevGreaterOrEqualElement[i]) * (nextGreaterElement[i] - i), k);
            res = (int)((1L * res * pow(num, operations)) % MOD);
            k -= operations;
            if (k == 0) {
                return res;
            }
        }

        return res;
    }

    int pow(int x, int n) {
        int res = 1;
        while (n > 0) {
            if (n % 2 == 1) {
                res = (int)((1L * res * x) % MOD);
            }
            x = (int)((1L * x * x) % MOD);
            n /= 2;
        }
        return res;
    }
};
