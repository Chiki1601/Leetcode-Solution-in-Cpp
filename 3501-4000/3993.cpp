class Solution {
public:
    long long maximumValue(int n, int s, int m) {

        if ( n == 1 ) return s ;

        long long numberOfBoxes = n/2 ;

        long long ans = 1LL*s + 1LL*m + ( numberOfBoxes-1 )*1LL * ( m-1 )*1LL ;

        return ans ;
        
    }
};
