class Solution {
public:
    int shortestSequence(vector<int>& rolls, int k) {
        const int n = rolls.size();

        unordered_set<int> seen;
        int ans = 1;
        for (int i = 0; i < n; i++) {
            if (seen.size() == k) {
                ans++;
                seen.clear();
            }

            seen.insert(rolls[i]);
        }

        if (seen.size() == k)
            ans++;

        return ans;
    }
};
