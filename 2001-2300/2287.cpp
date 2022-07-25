class Solution {
public:
    int rearrangeCharacters(string s, string t) {
        unordered_map<char, int> ms, mt;
        for(auto c : s) ms[c]++;
        for(auto c : t) mt[c]++;
        int ans = INT_MAX;
        for(auto [k, v] : mt){
            ans = min(ans, ms[k] / v);
        }
        return ans == INT_MAX ? 0 : ans;
    }
};
