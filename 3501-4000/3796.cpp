class Solution {
public:
    int findMaxVal(int n, vector<vector<int>>& res, vector<int>& diff) {
        vector<int> ans(n, INT_MAX);
        // 0 index with 0 value
        ans[0] = 0;
        for (auto &r : res) {
            int idx = r[0];
            int val = r[1];
            ans[idx] = min(ans[idx],val);
        }
        //Forward Pass
        for(int i=1;i<n;i++){
            int diff_forward=ans[i-1]+diff[i-1];
            ans[i]=min(ans[i],diff_forward);
        }
        //Backward Pass
        for(int i=n-2;i>=0;i--){
            int diff_backward=ans[i+1]+diff[i];
            ans[i]=min(ans[i],diff_backward);
        }
        //max element
        int result = *max_element(ans.begin(), ans.end());
        return result;
    }
};
