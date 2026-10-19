class Solution {
public:
    int minDeletions(vector<int>& nums) {
        int k = 0;

        for (int i = 1; i < nums.size(); i++) {
            if ((nums[i - 1] ^ nums[i]) == 0) {
                k++;
            }
        }

        return k;
    }
};
