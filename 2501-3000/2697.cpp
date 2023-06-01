class Solution {
public:
    string makeSmallestPalindrome(string s) {
        int i = 0, j = s.length()-1;//make pointer index
        while(i<j){
            if(s[i] != s[j]){
                s[i] = s[j] = min(s[i],s[j]);//initialise i and j to min of (s[i],s[j]);
            }
            i++;j--;
        }
        return s;
    }
};
