class Solution {
public:
    bool small(char c){
        return c<='z' and c>='a';
    }
    bool big(char c){
        return c<='Z' and c>='A';
    }
    bool num(char c){
        return c<='9' and c>='0';
    }
    bool sp(char c){
        return c=='!' or c=='@' or c=='#' or c=='$';
    }
    int passwordStrength(string s) {
        int ans=0;
        unordered_set<char> st(s.begin(),s.end());
        for(auto c:st){
            if(small(c)) ans++;
            else if(big(c)) ans+=2;
            else if(num(c)) ans+=3;
            else if(sp(c)) ans+=5;
        }
        return ans;
    }
};
