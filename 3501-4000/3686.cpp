class Solution
{
public:
    int countStableSubsequences(vector<int> &nums)
    {
        const int mod = 1e9 + 7;
        int n = nums.size();
        long odd = 0, even = 0, odd_odd = 0, even_even = 0;
        // odd -> count of subsequences ending with one odd number
        // even -> count of subsequences ending with one even number
        // odd_odd -> count of subsequences ending with two odd numbers
        // even_even -> count of subsequences ending with two even numbers
        // single element subsequences are also counted

        for (int i : nums)
        {
            if (i & 1) // odd
            {
                odd_odd += odd;
                // append odd to all subsequences ending with one odd number to make them end with two odd numbers

                odd++; // single element subsequence

                // append odd to all subsequences ending with an even number to make them end with one odd number
                odd += even;
                odd += even_even;

                odd_odd %= mod;
                odd %= mod;
            }
            else // even
            {
                even_even += even;
                // append even to all subsequences ending with one even number to make them end with two even numbers

                even++; // single element subsequence

                // append even to all subsequences ending with an odd number to make them end with one even number
                even += odd;
                even += odd_odd;

                even_even %= mod;
                even %= mod;
            }
        }
        return (odd + even + odd_odd + even_even) % mod;
    }
};
