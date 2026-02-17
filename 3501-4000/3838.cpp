class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string ans = "";
        
        for (auto &word : words) {
            int sum = 0;
            for (auto ch : word) {
                sum += weights[ch - 'a'];
            }
            sum %= 26;
            ans += 'a' + 26 - sum - 1;
        }

        return ans;
    }
};
