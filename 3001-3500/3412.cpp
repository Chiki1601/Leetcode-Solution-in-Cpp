class Solution {
public:
  long long calculateScore(string s) {
    long long ans = 0;
    unordered_map<int, vector<int>> mp;
    for(int i= 0; i < s.size(); ++i){
        int cur = s[i] - 'a', mirror = 25 - cur;
        if(mp.find(mirror) != mp.end() && mp[mirror].size() > 0){
            ans += (long long)i - (long long)mp[mirror].back();
            mp[mirror].pop_back();
        }else mp[cur].push_back(i);
    }
    return ans;
}
};
