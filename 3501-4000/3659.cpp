class Solution {
public:
    bool partitionArray(vector<int>& nums, int k) {

        unordered_map <int,int> mpp;
        for (int x : nums) {
            mpp[x]++;
        }

        for (auto& p : mpp) {
            if (p.second > nums.size() / k) {
                return false;
            }
        }
        return nums.size() % k == 0;
    }
};
