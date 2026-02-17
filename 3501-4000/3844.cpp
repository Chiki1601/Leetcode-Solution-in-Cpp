class Solution {
public:
    int f(int i,int j,int n,string &s){
        int len=0;
        while(i>=0 && j<n){
            if(s[i]==s[j]){
                    i--;
                    j++;
            }
                else break;
        }
        //i-1 to j-1 is palindrome
        len=j-i-1;
        if(len==n) return n-1;
        //case-1
        int i1=i-1;int j1=j;
        while(i1>=0 && j1<n){
            if(s[i1]==s[j1]){
                    i1--;
                    j1++;
            }
                else break;
        }
        len=max(len,j1-i1-1);
        //case-2
        i1=i;j1=j+1;
        while(i1>=0 && j1<n){
            if(s[i1]==s[j1]){
                    i1--;
                    j1++;
            }
                else break;
        }
        len=max(len,j1-i1-1);
        return len;
    }
    int almostPalindromic(string s) {
        int maxi=0;
        int n=s.length();
        for(int c=0;c<n;c++){
            int len_even=0,len_odd=0;
            len_even=f(c,c+1,n,s);
            len_odd=f(c,c,n,s);
            maxi=max({maxi,len_even,len_odd});
        }
        return maxi;
    }
};
