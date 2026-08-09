class Solution {
public:
    double minPrice(vector<int>& prices, vector<int>& discounts) {

        int n = prices.size() ;
        int m = discounts.size() ;

        sort( prices.rbegin() , prices.rend() ) ;
        sort( discounts.rbegin() , discounts.rend() ) ;

        double ans = 0 ;

        int i = 0 ;
        int j = 0 ;
        
        while ( i < n && j < m ) {

            ans += (double)( prices[i] * (double)(100-discounts[j]) / 100 ) ;
            i++ ;
            j++ ;
            
        }

        while ( i < n ) ans += prices[i++] ;

        return ans ;
        
    }
};
