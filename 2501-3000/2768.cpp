class Solution {
public:
    vector<long long> countBlackBlocks(int m, int n, vector<vector<int>>& coordinates) {
    unordered_map<long long, int> mp;
    for(auto c: coordinates) {
        if(c[0] < m - 1 && c[1] < n-1) mp[ (long long)c[1] * 1000000L +  c[0]]++;          
        if(c[0] - 1 >= 0 && c[1] < n-1) mp[ (long long)c[1] * 1000000L+  (c[0] - 1)]++;
        if(c[1] - 1 >= 0 && c[0] < m-1) mp[ (long long)(c[1] -1) * 1000000L +  c[0]]++;
        if(c[0] - 1 >= 0 && c[1] - 1 >= 0) mp[ (long long)(c[1] -1) * 1000000L +  (c[0] - 1)]++;
    }
    vector<long long> ans(5, 0);
    for(auto m:mp) ans[m.second]++;     //iterate map and update the ans as per the count each map value have 
    ans[0] = (long long)(m-1)* (long long)(n-1);  //total possible blocks count
    ans[0] = ans[0] - ans[1] - ans[2] - ans[3] - ans[4];  //remove counts those have black more than 1
    return ans;
}
};
