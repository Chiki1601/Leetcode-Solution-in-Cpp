class Solution {
    set<pair<int, pair<int, int>>> s1;
public:
    bool start(int i, int j, int flag, string &word1, string &word2, vector<int> &sol) {
        if (j >= word2.size()) return true;
        if (i >= word1.size()) return false;
        if (s1.count({i, {j, flag}})) return false;

        bool f1 = false;

        if (word1[i] == word2[j]) {
            f1 = start(i + 1, j + 1, flag, word1, word2, sol);
            if (f1) sol.push_back(i);
            return f1;
        } else {
            if (flag > 0) {
                f1 = start(i + 1, j + 1, 0, word1, word2, sol);
                if (f1) {
                    sol.push_back(i);
                    return true;
                }
            }

            while (i < word1.size() && word1[i] != word2[j]) i++;
            if (i < word1.size()) {
                f1 = start(i + 1, j + 1, flag, word1, word2, sol);
                if (f1) {
                    sol.push_back(i);
                    return true;
                }
            }
        }

        s1.insert({i, {j, flag}});
        return f1;
    }

    vector<int> validSequence(string word1, string word2) {
        vector<int> sol;
        if (start(0, 0, 1, word1, word2, sol)) {
            reverse(sol.begin(), sol.end());
            if (sol.size() == word2.size()) return sol;
        }
        return {};
    }
};
