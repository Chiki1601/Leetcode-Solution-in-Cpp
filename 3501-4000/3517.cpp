class Solution {
public:
    string smallestPalindrome(string s) {
        int  n = s.size(), m = n/2;
        if(n==1 || n==2) return s;

        string f = s.substr(0, n/2);      //half string generation
        sort(f.begin(), f.end());

        string rev = f;
        reverse(rev.begin(), rev.end());  // reversal

        if((n%2) ==1) f += s[m];          // append middle char as is if n is odd
        return f + rev;                   // concatenate
    }
};
