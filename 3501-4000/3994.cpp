class Solution {
public:
    int mod = 1e9 + 7; 
    int minAdjacentSwaps(vector<int>& nums, int a, int b) {
        // we can swap two neighbouring elements 
        // part 1 <= a, part 2 [a, b], part 3 >= b 

        // min swaps to make nums good. 
        // we have to take a module 
        // any part can be empty 

        // given a < b 

        // for all less than <= a -> can be converted to a 
        // for all greater than >= b -> can be converted to b 
        // only three type exists 0 1 2 
         // a = 0 
        // b = 1
        // c = 2; 
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] < a) nums[i] = 0; 
            else if(nums[i] > b) nums[i] = 2; 
            else nums[i] = 1; 
            // Now for those btw [a, b] -> what can I make them
        }
        // I have only three types now 0 1 2 
        long long cnt1 = 0, cnt2 = 0; 
        long long swaps = 0; 
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == 0) {
                // this must cross all 1's and 2's before it
                swaps = (swaps + cnt1 + cnt2) % mod; 
            } else if(nums[i] == 1) {
                // must corss all cnt2 befor it 
                swaps = (swaps + cnt2) % mod; 
                cnt1++; 
            } else cnt2++; 
        }
        return swaps; 
    }
};
