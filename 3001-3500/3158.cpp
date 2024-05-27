class Solution {
public:
  int duplicateNumbersXOR(vector<int>& nums) {
    unordered_set<int> s(begin(nums), end(nums));
    return accumulate(begin(nums), end(nums), accumulate(begin(s), end(s), 0, bit_xor{}), bit_xor{});
}
};
