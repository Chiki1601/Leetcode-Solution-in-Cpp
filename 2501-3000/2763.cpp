class Solution {
public:
       int sumImbalanceNumbers(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            unordered_set<int> s;
            int curr = 0;
            for (int j = i; j < n; j++) {
                int x = nums[j];
                if (s.count(x)) {
                    // do nothing
                } else if (s.count(x - 1) && s.count(x + 1)) {
                    curr--;
                } else if (!s.count(x - 1) && !s.count(x + 1) && !s.empty()) {
                    curr++;
                }
                s.insert(x);
                ans += curr;
            }
        }
        return ans;
    }
};
