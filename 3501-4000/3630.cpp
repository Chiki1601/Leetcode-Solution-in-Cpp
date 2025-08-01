class Solution {
public:

    // out current implementation is O(3^19) theoretically
    // try to prune the solution and exist early when needed to pass the test cases

    int n; 
    long long maxi = 0;
    vector<int> nums;
    vector<long long> sufOR;

    long long maximizeXorAndXor(vector<int>& input) {
        nums = input;
        n = nums.size();

        // taking initial bound on maxi 
        long long AND = -1ll;
        for (int x : nums) AND &= x;
        maxi = max(maxi, AND);

        long long XOR = 0;
        for (int x : nums) XOR ^= x;
        maxi = max(maxi, XOR);

        long long prefXOR = 0;
        for (int x : nums) {
            prefXOR ^= x;
            maxi = max(maxi, prefXOR + (XOR ^ prefXOR));
        }

        // trying from largest values first to exit early while pruning
        sort(rbegin(nums), rend(nums));

        sufOR.resize(n);
        sufOR[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            sufOR[i] = sufOR[i + 1] | nums[i];
        }

        recur(1, nums[0], -1, 0);
        recur(1, 0, nums[0], 0);
        // recur(1, 0, -1, arr[0]) --> not calling this one because it's symmetric to first one

        return maxi;
    }

    void recur(int i, long long a, long long b, long long c) {
        if (i == n) {
            long long sum = a + c + (b == -1 ? 0 : b);
            maxi = max(maxi, sum);
            return;
        }

        long long maxb = (b != -1) ? b : sufOR[i];
        long long bound = (a | sufOR[i]) + (c | sufOR[i]) + maxb;

        if (bound <= maxi) return;

        // try arr[i] in either a, b or c parition
        long long val = nums[i];
        recur(i + 1, a ^ val, b, c);
        if (b == -1)
            recur(i + 1, a, val, c);
        else
            recur(i + 1, a, b & val, c);
        recur(i + 1, a, b, c ^ val);
    }
};
