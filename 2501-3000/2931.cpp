class Solution {
public:
    // Function to calculate the maximum spending
    long long maxSpending(std::vector<std::vector<int>>& values) {
        // Alias for long long data type
        using ll = long long;

        // Vector to store all values from the input vector of vectors
        std::vector<ll> a;

        // Flatten the 2D vector into a 1D vector
        for(auto v : values)
            for(auto x : v)
                a.push_back(x);

        // Sort the values in ascending order
        std::sort(a.begin(), a.end());
        
        // Variable to store the final result
        ll ans = 0;

        // Calculate the maximum spending
        for(ll i = 0; i < a.size(); i++)
            ans += a[i] * (i + 1);

        // Return the maximum spending
        return ans;
    }
};
