class Solution {
public:
    vector<int> maximumSumQueries(vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& q) {
        int n = nums1.size();

        // Step 1: Create a vector of pairs and sort it in reverse order based on the first element (nums1)
        vector<pair<int, int>> vec;
        for (int i = 0; i < n; i++) {
            vec.emplace_back(nums1[i], nums2[i]);
        }
        sort(vec.rbegin(), vec.rend());
        assert(vec.size() == n);

        // Step 2: Create a vector of indices and sort it based on the queries in descending order
        vector<int> ord(q.size());
        iota(ord.begin(), ord.end(), 0);
        sort(ord.begin(), ord.end(), [&](auto& x, auto& y) {
            return q[x] > q[y];
        });

        // Step 3: Create a map to store the maximum sum for each value of x
        map<int, int> val;
        int l = 0;
        vector<int> ans(q.size());

        // Step 4: Process the queries and find the maximum sums
        for (int& i : ord) {
            // Process the remaining elements in the vector of pairs
            while (l < n && vec[l].first >= q[i][0]) {
                auto [y, x] = vec[l++];

                // Check if there is a higher value of x already present in the map
                if (val.lower_bound(x) != val.end() && val.lower_bound(x)->second >= x + y)
                    continue;

                auto it = val.lower_bound(x);
                while (it != val.begin()) {
                    it--;
                    if (it->second < x + y) {
                        val.erase(it);
                    } else {
                        break;
                    }
                    it = val.lower_bound(x);
                }

                // Store the maximum sum for this value of x
                val[x] = x + y;
            }

            // Find the answer for the current query
            if (val.lower_bound(q[i][1]) == val.end()) {
                ans[i] = -1;
            } else {
                ans[i] = val.lower_bound(q[i][1])->second;
            }
        }

        return ans;
    }
};
