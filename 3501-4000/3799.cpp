class Solution {
public:
    vector<vector<string>> wordSquares(vector<string>& words) {
        auto s = words; // Store input midway
        sort(s.begin(), s.end());
        vector<vector<string>> result;
        int n = s.size();
        
        // Try all combinations of 4 distinct words
        for (int a = 0; a < n; ++a) {
            for (int b = 0; b < n; ++b) {
                // Constraint 1: top[0] == left[0]
                if (a != b && s[a][0] == s[b][0]) {
                    for (int c = 0; c < n; ++c) {
                        // Constraint 2: top[3] == right[0]
                        if (c != a && c != b && s[a][3] == s[c][0]) {
                            for (int d = 0; d < n; ++d) {
                                // Constraint 3: bottom[0] == left[3]
                                // Constraint 4: bottom[3] == right[3]
                                if (d != a && d != b && d != c && 
                                    s[d][0] == s[b][3] && 
                                    s[d][3] == s[c][3]) {
                                    result.push_back({s[a], s[b], 
                                                     s[c], s[d]});
                                }
                            }
                        }
                    }
                }
            }
        }
        return result;
    }
};
