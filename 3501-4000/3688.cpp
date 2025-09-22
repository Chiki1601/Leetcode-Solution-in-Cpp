class Solution {
public:
    int evenNumberBitwiseORs(vector<int>& nums) {
        int result = 0;
        for (int i = 1; i <= 6; i++) {
            for (int num : nums) {
                if ((~num & 1) & ((num >> i) & 1)) {
                    result |= (1 << i);
                    break;
                }
            }
        }
        return result;
    }
};
