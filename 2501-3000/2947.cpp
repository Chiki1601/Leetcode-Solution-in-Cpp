class Solution {
public:
    unordered_set<char> st{'a', 'e', 'i', 'o', 'u'};
    bool isVowel(char c) { return st.find(c) != st.end(); }
    int beautifulSubstrings(string s, int k) {
        int ans = 0;
        for(int i = 0; i < s.size(); ++i){
            int vow = 0, con = 0;
            for(int j = i; j < s.size(); ++j) {
                (isVowel(s[j]))? vow++: con++;
                if(vow == con && (vow*con)%k == 0) ans++;
            }
        }
        return ans;
    }
};
