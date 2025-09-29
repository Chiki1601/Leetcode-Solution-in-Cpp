class Solution {
public:
    string majorityFrequencyGroup(string s) {

        unordered_map<char,int> arr;

        for(auto str: s) {
            arr[str]++;
        }

        unordered_map<int,vector<char>> mp;

        string ans = "";
        for(auto it: arr) {
            mp[it.second].push_back(it.first);
        }

        int maxGroupSize = 0;
        int maxFreqK = 0;

        for(auto it: mp) {

            if(it.second.size() > maxGroupSize) {
                maxGroupSize = it.second.size();
                maxFreqK = it.first;
                ans = "";
                for(auto a: it.second) {
                    ans += a;
                }
            }
            else if(it.second.size() == maxGroupSize && maxFreqK < it.first) {
                maxGroupSize = it.second.size();
                maxFreqK = it.first;
                ans = "";
                for(auto a: it.second) {
                    ans += a;
                }
            }
        }

        return ans;
        
    }
};
