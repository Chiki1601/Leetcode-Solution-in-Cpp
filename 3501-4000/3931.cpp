class Solution {
public:
    bool isAdjacentDiffAtMostTwo(string s) {
        for(int i=1;i<s.size();i++){
            int a=s[i]-'0';
            int b=s[i-1]-'0';
            if(abs(a-b)>2)return false;
        }
        return true;
    }
};
