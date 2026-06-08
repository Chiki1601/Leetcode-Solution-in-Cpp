class Solution {
    // Given penalty C ke liye max sum aur max subarrays nikalne ke liye helper function
    pair<long long, int> calc(long long C, int n, int l, int r, const vector<long long>& p) {
        vector<long long> dp(n + 1, 0);
        vector<int> cnt(n + 1, 0);
        deque<int> dq;
        
        auto get_val = [&](int a) {
            return make_pair(dp[a] - p[a], cnt[a]);
        };
        
        for (int i = 1; i <= n; i++) {
            // Option 1: Current element ko skip karo
            dp[i] = dp[i - 1];
            cnt[i] = cnt[i - 1];
            
            int a = i - l;
            if (a >= 0) {
                // (dp[a] - p[a], cnt[a]) ke basis par monotonic decreasing deque maintain karo
                while (!dq.empty() && get_val(dq.back()) <= get_val(a)) {
                    dq.pop_back();
                }
                dq.push_back(a);
            }
            
            // Jo indices valid length window ke bahar hain, unhe hatao
            while (!dq.empty() && dq.front() < i - r) {
                dq.pop_front();
            }
            
            // Option 2: Ek subarray banao jo i par end ho
            if (!dq.empty()) {
                int f = dq.front();
                // Subarray candidate par penalty C lagao
                long long cand_val = p[i] + dp[f] - p[f] - C; 
                int cand_cnt = cnt[f] + 1;
                
                // Hume sum maximize karna hai; tie hone par subarray count maximize karna ZAROORI hai
                if (cand_val > dp[i] || (cand_val == dp[i] && cand_cnt > cnt[i])) {
                    dp[i] = cand_val;
                    cnt[i] = cand_cnt;
                }
            }
        }
        return {dp[n], cnt[n]};
    }
    
    // DP ko exactly K subarrays pick karne ke liye penalty par binary search lagao
    long long solve_k(int K, int n, int l, int r, const vector<long long>& p) {
        long long low = -1e11, high = 1e11, ans = -2e18;
        while (low <= high) {
            long long mid = low + (high - low) / 2;
            auto res = calc(mid, n, l, r, p);
            
            if (res.second >= K) {
                // True sum record karne ke liye lagayi gayi penalty ko mathematically reverse karo
                ans = res.first + K * mid;
                low = mid + 1; // Subarray count kam karne ke liye heavier penalty lagane ki koshish karo
            } else {
                high = mid - 1; // Penalty bohot heavy hai, isliye count bohot kam aaya
            }
        }
        return ans;
    }
    
public:
    long long maximumSum(vector<int>& nums, int m, int l, int r) {
        int n = nums.size();
        if (n < l) return 0;
        
        vector<long long> p(n + 1, 0);
        for (int i = 0; i < n; i++) {
            p[i + 1] = p[i] + nums[i];
        }
        
        // 0 penalty ke sath optimal state find karo
        auto res0 = calc(0, n, l, r, p);
        
        if (res0.second > m) {
            // Agar optimal choice bina constraint ke > m subarrays use karti hai, toh usko m tak force karo
            return solve_k(m, n, l, r, p);
        } else if (res0.second >= 1) {
            // Optimal choice naturally [1, m] subarrays ke andar aati hai
            return res0.first;
        } else {
            // Optimal choice 0 subarrays hai (saare elements negative hain). Humein exactly 1 pick karna hi hoga
            return solve_k(1, n, l, r, p);
        }
    }
};
