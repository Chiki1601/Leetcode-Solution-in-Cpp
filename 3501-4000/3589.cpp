int MX = 50005;

class Solution {
public:
    vector<bool> SieveOfEratosthenes(int n) {
        vector<bool> prime(n + 1, true);
        prime[0] = false, prime[1] = false;
        
        for (int p = 2; p * p <= n; p++) {
            if (prime[p]) {
                for (int i = p * p; i <= n; i += p) {
                    prime[i] = false;
                }
            }
        }

        return prime;
    }
    
    int primeSubarray(vector<int> &nums, int k) {
        int n = nums.size();

        vector<bool> primes = SieveOfEratosthenes(MX);

        vector<int> prefSum(n);
        prefSum[0] = primes[nums[0]];
        for(int i = 1; i < n; i++) {
            prefSum[i] = prefSum[i - 1] + primes[nums[i]];
        }

        vector<int> startFrom(n);
        for(int i = 0; i < n; i++) {
            int start = i, end = n - 1, idx = -1;
            while(start <= end) {
                int mid = start + (end - start) / 2;

                int total = prefSum[mid] - (i - 1 >= 0 ? prefSum[i - 1] : 0);
                if(total >= 2) {
                    idx = mid;
                    end = mid - 1;
                } else {
                    start = mid + 1;
                }
            }
            startFrom[i] = idx;
        }

        int ans = 0;
        multiset<int> mst;
        int j = 0;
        for(int i = 0; i < n; i++) {
            if(startFrom[i] == -1) break;

            while(j < n) {
                if(primes[nums[j]]) mst.insert(nums[j]);
                
                if(mst.size() >= 2) {
                    if(*mst.rbegin() - *mst.begin() > k) {
                        if(primes[nums[j]]) mst.erase(mst.find(nums[j]));
                        break;
                    }
                }

                j++;
            }

            if(j > startFrom[i]) {
                ans += (j - startFrom[i]);
            }

            if(primes[nums[i]]) mst.erase(mst.find(nums[i]));
        }

        return ans;
    }
};
