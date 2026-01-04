class Solution {
public:
    string reversePrefix(string s, int k) {
        return reverse(s.begin(),s.begin()+k) , s;
    }
};
