class Solution {
public:
    bool helper(string& s) {
        int N = s.size(); 
        for(int i = 1; i < N; ++i) {
            if(s[i] == s[i-1]) return false; 
        }
        return true;
    }
    void genPermut(string& s, int n) {
        if(s.size() == n) {
            if(helper(s)) 
                res.push_back(s); 
            return;
        }
        for(char ch : {'a', 'b', 'c'}) {
            s.push_back(ch);
            genPermut(s, n);
            s.pop_back();
        }
    }
    vector<string> res;
    string getHappyString(int n, int k) {
        string s = "";
        genPermut(s, n);

        if(res.size() < k) return "";
        else return res[k-1]; 
    }
};
