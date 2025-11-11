#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n = nums.size();
        int ans = INT_MAX;
        unordered_map<int, vector<int>> mp;

        // Store all indices for each number
        for (int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }

        // Check each list of indices
        for (auto& [num, list] : mp) {
            if (list.size() < 3) continue; // Need at least 3 occurrences

            // Compute distance for first triplet
            int id1 = list[0], id2 = list[1], id3 = list[2];
            ans = min(ans, abs(id1 - id2) + abs(id2 - id3) + abs(id3 - id1));

            // Slide the window of size 3 across the list
            for (int i = 3; i < (int)list.size(); i++) {
                id1 = id2;
                id2 = id3;
                id3 = list[i];
                ans = min(ans, abs(id1 - id2) + abs(id2 - id3) + abs(id3 - id1));
            }
        }

        return ans == INT_MAX ? -1 : ans; // Return -1 if no valid triplet
    }
};
