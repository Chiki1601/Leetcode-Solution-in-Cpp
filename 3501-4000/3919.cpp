class Solution {
public:
    using ll = long long;
    
    vector<int> minCost(vector<int>& A, vector<vector<int>>& queries) {
        int n = A.size();
        
        vector<ll> LR(n), RL(n);
        LR[1] = RL[n - 2] = 1;
        
        for(int i = 1; i < n - 1; ++i) {
            ll diff_right = (ll)A[i + 1] - A[i], diff_left = (ll)A[i] - A[i - 1];
            LR[i + 1] = LR[i] + ((diff_right < diff_left) ? 1 : diff_right);
        }

        for(int i = n - 2; i > 0; --i) {
            ll diff_left = (ll)A[i] - A[i - 1], diff_right = (ll)A[i + 1] - A[i];
            RL[i - 1] = RL[i] + ((diff_right >= diff_left) ? 1 : diff_left);
        }

        vector<int> res(queries.size());
        int i = 0;
        
        for(auto& q : queries) {
            int l = q[0], r = q[1];

            if(l <= r) 
                res[i++] = LR[r] - LR[l];

            else
                res[i++] = RL[r] - RL[l];
        }

        return res;
    }
};
