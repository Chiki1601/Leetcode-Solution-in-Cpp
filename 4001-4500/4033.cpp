class Solution {
public:
    vector<bool> validSubarrays(
        vector<int>& nums,
        int k,
        vector<vector<int>>& queries
    ) {
        int n = nums.size();
        int q = queries.size();

        // Coordinate compression
        vector<int> values = nums;
        sort(values.begin(), values.end());
        values.erase(unique(values.begin(), values.end()), values.end());

        vector<int> compressed(n);

        for (int i = 0; i < n; i++) {
            compressed[i] = lower_bound(
                values.begin(),
                values.end(),
                nums[i]
            ) - values.begin();
        }

        int blockSize = sqrt(n);

        vector<int> order(q);
        iota(order.begin(), order.end(), 0);

        // Mo's Algorithm sorting
        sort(order.begin(), order.end(), [&](int a, int b) {
            int blockA = queries[a][0] / blockSize;
            int blockB = queries[b][0] / blockSize;

            if (blockA != blockB) {
                return blockA < blockB;
            }

            // Zig-zag ordering for better performance
            if (blockA & 1) {
                return queries[a][1] > queries[b][1];
            }

            return queries[a][1] < queries[b][1];
        });

        vector<int> freq(values.size(), 0);
        vector<bool> answer(q);

        int distinctCount = 0;
        int oddCount = 0;

        auto add = [&](int index) {
            int x = compressed[index];

            if (freq[x] == 0) {
                distinctCount++;
            }

            // Remove previous odd contribution
            if (freq[x] % 2 == 1) {
                oddCount--;
            }

            freq[x]++;

            // Add new odd contribution
            if (freq[x] % 2 == 1) {
                oddCount++;
            }
        };

        auto remove = [&](int index) {
            int x = compressed[index];

            // Remove previous odd contribution
            if (freq[x] % 2 == 1) {
                oddCount--;
            }

            freq[x]--;

            // Add new odd contribution
            if (freq[x] % 2 == 1) {
                oddCount++;
            }

            if (freq[x] == 0) {
                distinctCount--;
            }
        };

        int left = 0;
        int right = -1;

        for (int queryIndex : order) {
            int ql = queries[queryIndex][0];
            int qr = queries[queryIndex][1];

            while (left > ql) {
                add(--left);
            }

            while (right < qr) {
                add(++right);
            }

            while (left < ql) {
                remove(left++);
            }

            while (right > qr) {
                remove(right--);
            }

            answer[queryIndex] =
                (distinctCount == k && oddCount == 0);
        }

        return answer;
    }
};
