class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
    vector<int> gap(1, startTime[0]);
    for(int i = 1; i < startTime.size(); ++i) gap.push_back(startTime[i] -  endTime[i-1]);
    gap.push_back(eventTime - endTime.back());
    int ans = 0, sum = 0;
    for(int i = 0; i < gap.size(); ++i){
        sum += gap[i] - ((i >=  k+1)? gap[i - (k+1)] : 0);
        ans = max(ans, sum);
    }
    return ans;
}
};
