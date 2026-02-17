class Solution {
public:
    int firstUniqueFreq(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> m, m1;

        // Count frequency of each number
        for (int i : nums) {
            m[i]++;
        }

        // Count how many numbers have a particular frequency
        for (auto i : m) {
            m1[i.second]++;
        }

        // Find first number whose frequency is unique
        for (int i = 0; i < n; i++) {
            if (m1[m[nums[i]]] == 1)
                return nums[i];
        }

        return -1;
    }
};
