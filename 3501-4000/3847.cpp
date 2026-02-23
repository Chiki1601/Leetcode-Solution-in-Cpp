class Solution {
public:
    int scoreDifference(std::vector<int>& nums) {
        int player = 0;
        int scores[2] = {0, 0};
        for (int game = 1; game <= nums.size(); ++game) {
            player ^= ((nums[game - 1] % 2) ^ (game % 6 == 0));
            scores[player] += nums[game - 1];
        }

        return scores[0] - scores[1];
    }
};
