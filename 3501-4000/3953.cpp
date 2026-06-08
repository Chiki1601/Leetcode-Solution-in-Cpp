#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    // Smallest Prime Factor Sieve
    vector<int> makeSpf(int limit) {
        vector<int> spf(limit + 1, -1);

        spf[0] = 0;
        spf[1] = 1;
        if (limit >= 2) spf[2] = 2;

        for (int i = 4; i <= limit; i += 2) {
            spf[i] = 2;
        }

        for (int i = 3; i * i <= limit; i += 2) {
            if (spf[i] == -1) {
                // Optimized inner loop: start from i*i, step by 2*i to skip even numbers
                for (int j = i * i; j <= limit; j += i * 2) {
                    if (spf[j] == -1) spf[j] = i;
                }
            }
        }
        
        // Fill remaining primes that are greater than sqrt(limit)
        for (int i = 3; i <= limit; i += 2) {
            if (spf[i] == -1) spf[i] = i;
        }

        return spf;
    }

    // Instantly breaks a number down into a list of its distinct prime components
    vector<int> get_primes(int n, vector<int>& spf) {
        vector<int> primes;
        while (n > 1) {
            int p = spf[n];
            primes.push_back(p);
            // Fast-forward to remove all occurrences of the current prime factor
            while (n % p == 0) {
                n /= p;
            }
        }
        return primes;
    }

    int maxScore(vector<int>& nums, int maxVal) {
        int maxi = 0;
        for (int i : nums) maxi = max(maxi, i);
        maxi = max(maxi, maxVal) + 1;

        // Initialize SPF array up to the dynamic maximum limit
        vector<int> spf = makeSpf(maxi);

        // Precompute Frequencies
        vector<int> freq(maxi, 0);
        for (int i : nums) {
            freq[i]++;
        }
        
        // Precompute Multiples
        vector<int> mults = freq;
        for (int i = 2; i < maxi; i++) {
            for (int j = 2 * i; j < maxi; j += i) {
                mults[i] += freq[j];
            }
        }

        int ans = freq[1] > 0 ? 1 : 0;

        for (int i = maxi - 1; i > 0; i--) {
            // Early Exit: if our current best score is already equal to or greater 
            // than 'i', no further score can possibly beat it.
            if (ans >= i) break;

            vector<int> primes = get_primes(i, spf);
            int k = primes.size();
            int nc = 0; // "non-coprime" count
            
            // Applying Inclusion-Exclusion via Bitmasks
            int total_subsets = (1 << k);
            for (int mask = 1; mask < total_subsets; ++mask) {
                int prod = 1;
                int bits = 0; // Represents j.bit_count()
                
                // Form the subset's composite divisor
                for (int j = 0; j < k; ++j) {
                    if ((mask >> j) & 1) {
                        prod *= primes[j];
                        bits++;
                    }
                }
                
                // Check subset parity
                if (bits & 1) {
                    nc += mults[prod]; // Odd: Add
                } else {
                    nc -= mults[prod]; // Even: Subtract
                }
            }
            
            // Adjust by subtracting exact matches of the candidate itself
            nc -= freq[i]; 
            
            // Calculate Modifications and Maximize Global Score
            // int mods = nc + (freq[i] > 0 ? freq[i]-1 : 1);
            // int mods =0;
            if(freq[i]>0){
                nc+= freq[i]-1;
            }
            else if(i<=maxVal){
                nc   = nc>0? nc: 1;
            }
            else continue;
            int score = i - nc;
            ans = max(ans, score);
        }
        
        return ans;
    }
};
