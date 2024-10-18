class Solution {
public:
   string stringHash(string s, int k) {
    string res  = "";
    for(int i = 0, sum = 0; i < s.size(); ++i){
        sum += s[i] - 'a';
        if((i+1)%k == 0) { res += ('a' + (sum %26));  sum = 0; }
    }
    return res;
}
};
