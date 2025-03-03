class Solution {
public:
  int countArrays(vector<int>& original, vector<vector<int>>& bounds) {
    int low = bounds[0][0], high = bounds[0][1], ans = high - low + 1;
    for(int i = 1; i < original.size(); ++i){
        int diff = original[i] - original[i-1];
        low = max(low + diff, bounds[i][0]);
        high = min(high + diff, bounds[i][1]);
        ans = min(ans, high - low + 1);
    }
    return ans < 0? 0: ans;
}
};
