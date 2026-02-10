class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size(), m = nums2.size();
        if(n < m) return maxScore(nums2, nums1, k);
        vector<vector<long long>> next(m + 1, vector<long long> (k + 1, -1e15)), curr;
        
        // base case 1
        for(int j = 0; j <= m; j++) next[j][0] = 0;

        for(int i = n - 1; i >= 0; i--){
            curr.assign(m + 1, vector<long long> (k + 1, -1e15));
            // base case 2
            for(int j = 0; j <= m; j++) curr[j][0] = 0;
            for(int j = m - 1; j >= 0; j--){
                for(int pair = 1; pair <= k; pair++){
                    curr[j][pair] = max({
                        1LL * nums1[i] * nums2[j] + next[j+1][pair-1],
                        next[j+1][pair],
                        next[j][pair],  
                        curr[j+1][pair]
                    });
                }
            }
            next = curr;
        }
        
        return curr[0][k];
    }
};
