class Solution {
public:
    int minimumAddedCoins(vector<int>& coins, int target) {
        sort(coins.begin(), coins.end());
        long maxReach = 0;
        int addedCoins = 0;
        for (int coin : coins) {
            while (coin > maxReach + 1) {
                maxReach += maxReach + 1;
                addedCoins++;
            }
            maxReach += coin;
        }
        while (maxReach < target) {
            maxReach += maxReach + 1;
            addedCoins++;
        }
        return addedCoins;
    }
};
