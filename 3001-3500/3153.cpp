class Solution {
public:
    long long sumDigitDifferences(vector<int>& v) {
        long long n = v.size(), ds = to_string(v[0]).size(), ans = 0;; // ds = digitSize of a number in nums
        vector<vector<int>> dc(ds, vector<int>(10,0)); // dc = frequency count of each number at a given digit 
        for(auto &it: v) for(int i = ds-1 ; i>=0;i--) dc[i][it%10]++, it/=10;
        for(auto i = 0;i<ds;i++) for(int j = 0;j<10;j++) ans+= dc[i][j]*(n - dc[i][j]);
        return ans/2;
    }
};
