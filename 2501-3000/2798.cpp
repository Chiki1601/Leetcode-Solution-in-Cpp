class Solution {
public:
    int numberOfEmployeesWhoMetTarget(vector<int>& hours, int target) {
    int ans = 0;
    for(auto h: hours) ans += (h >= target);
    return ans;
}
};
