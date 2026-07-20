struct PairHash {
    size_t operator()(const pair<string, string>& p) const{
        return hash<string>()(p.first) ^ (hash<string>()(p.second) << 1);
    }
};

class Solution {
private:
    string get_canonical_booth(const string& s) {
        if (s.empty()) return "";
        int n = s.length();
        string s2 = s + s;
        vector<int> f(2 * n, -1);
        int k = 0;

        for (int j = 1; j < 2 * n; ++j) {
            int i = f[j - k - 1];
            while (i != -1 && s2[j] != s2[k + i + 1]) {
                if(s2[j] < s2[k + i + 1]) {
                    k = j - i - 1;
                }
                i = f[i];
            }
            if (s2[j] != s2[k + i + 1]) {
                if (s2[j] < s2[k]) {
                    k = j;
                }
                f[j - k] = -1;
            } else {
                f[j - k] = i + 1;
            }
        }
        return s2.substr(k, n);
    }
public:
    int minimumGroups(vector<string>& words) {
        unordered_set<pair<string, string>, PairHash> unique_groups;

        for (const string& word : words) {
            string even_chars = "";
            string odd_chars = "";

            for (int i = 0; i < word.length(); ++i) {
                if (i % 2 == 0) {
                    even_chars += word[i];
                } else {
                    odd_chars += word[i];
                }
            }
            string norm_even = get_canonical_booth(even_chars);
            string norm_odd = get_canonical_booth(odd_chars);

            unique_groups.insert({norm_even, norm_odd});
        }
        return unique_groups.size();
        
    }
};
