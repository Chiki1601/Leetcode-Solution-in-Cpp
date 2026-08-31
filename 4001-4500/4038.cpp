class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        vector<int> b(101, 0);

        for(int i = 0; i < nums.size(); i++) {
            if(i == 0 || nums[i] != nums[i - 1]) {
                b[nums[i]]++;
            }
        }

        int ans = 0;

        for(int x = 1; x <= 100; x++) {
            if(b[x] == 1)
                ans++;
        }

        return ans;
    }
};
