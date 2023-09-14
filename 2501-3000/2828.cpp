class Solution {
public:
    bool isAcronym(vector<string>& words, string s) {
        int n = words.size();
        int m = s.length();
        if(n>m)
            return false;
        string str ="";
        for(auto word : words){
            str+=word[0];
        }
        return (s==str);
    }
};
