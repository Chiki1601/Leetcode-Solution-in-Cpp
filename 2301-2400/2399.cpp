class Solution {
public:
    bool checkDistances(string s, vector<int>& distance) {
            int n = s.size();
            for(int i = 0; i < n; i++) {
                char ch = s[i];
                for(int j = i + 1; j < n; j++) {
                    if(s[j] == ch) {
                        int dist = j - i - 1;
                        if(distance[ch - 'a'] != dist) return false;
                    }
                }
            }
        return true;
    }
};
