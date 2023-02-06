class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hash;
        vector<int> res;
        for (int i = 0; i < nums.size(); i++) {
            int numberToFind = target - nums[i];
            auto it = hash.find(numberToFind);
            if (it != hash.end()) {
                res.push_back(it->second); // to int
                res.push_back(i);
                return res;
            }
            hash[nums[i]] = i;
        }
        return res;
    }
};
