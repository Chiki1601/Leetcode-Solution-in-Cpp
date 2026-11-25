class Solution {
public:
    long long minCost(vector<int>& nums) {

        typedef long long ll;
        int n = nums.size();

        // first and last elements are always paid
        ll ans = (ll)nums[0] + (ll)nums[n-1];

        ll negativeSum = 0;
        ll negativeCount = 0;
        ll smallestAbsolute = LLONG_MAX;

        for(int i = 1; i < n-1; i++){

            // negatives in the middle reduce the cost, so take them all
            if(nums[i] < 0){
                negativeSum += nums[i];
                negativeCount++;
            }

            // cheapest element to flip if the parity is odd
            smallestAbsolute = min(smallestAbsolute, abs((ll)nums[i]));
        }

        ans += negativeSum;

        // paid count must be even, so fix the parity at the lowest penalty
        if(negativeCount % 2 == 1) ans += smallestAbsolute;

        return ans;
    }
};
