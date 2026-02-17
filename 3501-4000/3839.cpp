class Solution {
public:
    int prefixConnected(vector<string>& words, int k) {
        int res = 0, c = 0;
        sort(words.begin(), words.end());
        string curr = "";
        for (string s : words) {
            if (s.size() >= k) {
                if (curr == s.substr(0, k)) {
                    if (++c == 2) 
                        res++;
                } else {
                    c = 1;
                    curr = s.substr(0, k);
                } 
            }
        }
        return res;
    }
};
