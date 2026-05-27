class Solution {
public:
    using ull = unsigned long long;
    int smallestUniqueSubarray(vector<int>& nums) {
        int n = nums.size();

        const ull BASE = 911382323; //large random base to represent number
        // similar to 1234 = 1*10^3 + 2*10^2 + 3*10 + 4
        // hash = a*BASE^3 + b*BASE^2 + c*BASE + d

        vector<ull> power(n + 1, 1); // to store power of base
        vector<ull> pref(n + 1, 0); // pref[i] stores hash of first i elements.

        for (int i = 0; i < n; i++) {
            power[i + 1] = power[i] * BASE;
            pref[i + 1] = pref[i] * BASE + nums[i] + 1;
        }

        // give hash of subarray l to r
        auto getHash = [&](int l, int r) {
            return pref[r + 1] - pref[l] * power[r - l + 1];
        };

        // to check if there is any unique subarray of length len
        auto possible = [&](int len) {
            unordered_map<ull, int> freq;

            // generate all subarray hashes
            for (int i = 0; i + len - 1 < n; i++) {
                ull h = getHash(i, i + len - 1);
                freq[h]++;
            }
            // iterating over the map and checking if any subarray has freq 1
            for (auto &p : freq) {
                if (p.second == 1) return true;
            }

            return false;
        };

        int low = 1, high = n;
        int ans = n;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (possible(mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};
