class Solution {
public:
   bool isSubstringPresent(string s) {
    unordered_map<int, unordered_set<int>> ump;
    for(int i = 1; i < s.size(); ++i){
        ump[s[i-1]].insert(s[i]);
    }
    for(int i = 1; i < s.size(); ++i){
        if(ump[s[i]].find(s[i-1]) != ump[s[i]].end()) return true;
    }
    return false;
}
};
