class Solution {
public:
    int lis(vector<int>& nums){
        vector<int> res;
        for(int &x : nums){
            if(res.empty() || res.back() < x){
                res.push_back(x);
                continue;
            }
            auto it = lower_bound(res.begin(), res.end(), x);
            *it = x;
        }
        return res.size();
    }
    int longestSubsequence(vector<int>& nums) {
        int best = 0;
        for(int i = 0; i<31; i++){
            vector<int> curr;
            for(int&x : nums){
                if(x & (1 << i)){
                    curr.push_back(x);
                }
            }
            best = max(best, lis(curr));
        }
        return best;
    }
};
