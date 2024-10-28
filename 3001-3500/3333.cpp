class Solution {
public:
    int possibleStringCount(string word, int k) {
        int n = word.length();
        long long total = 1;
        const long long mod = 1e9 + 7;
        vector<int> segments;
        int cnt = 1;

        // Step 1: Segment consecutive identical characters in `word`
        // For example, if word = "aaabbc", segments will store [3, 2, 1]
        for (int i = 1; i < n; i++) {
            if (word[i] != word[i - 1]) {
                segments.push_back(cnt);  // Store the length of current segment
                cnt = 1;  // Reset count for new segment
            } else {
                cnt++;  // Increment count for consecutive character
            }
        }
        segments.push_back(cnt);  // Add the last segment count

        // Step 2: Calculate `total`, the product of all segment sizes (modulo `mod`)
        // This represents the total possible combinations considering each segment individually
        for (int i = 0; i < segments.size(); i++) {
            total = (total * segments[i]) % mod;
        }

        // Step 3: Initialize the first row of dynamic programming table `prev_row`
        // `prev_row[x]` represents the number of ways to form a valid substring
        // ending with `x` characters from the first segment.
        vector<int> prev_row(k + 1, 0);
        for (int x = 1; x <= min(segments[0], k - 1); x++) {
            prev_row[x] = 1;  // Set ways to 1 for initial segment
        }

        // Initialize temporary vectors for calculations in later segments
        vector<int> curr_row(k + 1, 0);   // Stores ways for the current segment
        vector<int> prefix(k + 1, 0);     // Stores cumulative sums for efficient range calculations

        int a = segments.size();  // Number of segments
        // Step 4: Process each subsequent segment up to `k` segments (to avoid over-calculation)
        for (int i = 1; i < min(a, k); i++) {     
            // Compute cumulative sums in `prefix` for `prev_row`
            prefix[0] = prev_row[0];
            for (int x = 1; x <= k; x++) {
                prefix[x] = (prefix[x - 1] + prev_row[x]) % mod;  // Prefix sum mod `mod`
            }

            // Calculate current row `curr_row` using prefix sums
            for (int x = 1; x <= k; x++) {
                int prev_point = max(x - segments[i], i);
                // Calculate ways for current position x using the prefix array
                curr_row[x] = (prefix[x - 1] - prefix[prev_point - 1] + mod) % mod;
            }
            prev_row = curr_row;  // Move current row to previous row for next iteration
        }

        // Step 5: Calculate `t2`, which is the sum of possible substrings of length `k`
        long long t2 = 0;
        for (int i = 0; i < k; i++) {
            t2 = (t2 + prev_row[i]) % mod;
        }

        // Step 6: Return the result as (total - t2) modulo `mod`
        // `total` is all combinations, and `t2` removes those not meeting the criteria
        return (total - t2 + mod) % mod;
    }
};
