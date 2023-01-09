class Solution {
public:
    static int xorBeauty(const vector<int>& nums) {
        return accumulate(begin(nums), end(nums), 0, bit_xor{});
    }
};
