class Solution {
public:
    vector<string> findHighAccessEmployees(vector<vector<string>>& access_times) {
        unordered_map<string, vector<int>> mp;
        for (auto& it : access_times) {
            int time = stoi(it[1]);
            mp[it[0]].push_back(time);
        }
        for (auto& it : mp) {
            sort(it.second.begin(), it.second.end());
        }
        vector<string> ans;
        for (auto& it : mp) {
            vector<int>& times = it.second;
            for (int i = 2; i < times.size(); i++) {
                if (times[i] - times[i - 2] < 100) {
                    ans.push_back(it.first);
                    break;
                }
            }
        }
        return ans;

    }
};
