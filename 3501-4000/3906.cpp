
class Solution {
public:
    long long dp[20][10][2][2];
    unordered_set<int> indices ;
    long long solve( int ind , int pre , int tightL , int tightR , string & L , string & R ){

        if( ind == L.size())return 1 ; 
        long long & ans = dp[ind][pre][tightL][tightR];
        if( ans != -1 )return ans ;

        int l = tightL ?( L[ind] - '0') : 0 ; 
        int r = tightR ? (R[ind] - '0') : 9 ;

        long long c = 0 ; 

        for( int j = l ;  j <= r ; j++){
            if( !indices.count( ind ) ){
                c += solve( ind + 1 , pre , ( tightL & ( j == l )) , ( tightR & (j==r)) , L , R ) ;
                continue; 
            }
            if( pre > j ) continue;
            c += solve( ind + 1 , j , ( tightL & ( j == l )) , ( tightR & (j==r)) , L , R ) ;
        }
        return ans = c ; 
    }
    long long countGoodIntegersOnPath(long long l, long long r, string directions) {
        memset( dp , -1 ,sizeof(dp));
        string a = to_string(l) , b = to_string(r);
        int ind = 0 ; indices.insert( ind );
        for( auto i : directions) {
            ind += ( i == 'D' ? 4 : 1); 
            indices.insert( ind );
        }
        while( a.size() < 16 )a.insert(a.begin() , '0');
        while( b.size() < 16 )b.insert(b.begin() , '0');
        return solve( 0 , 0 , 1 , 1 , a , b );
    }
};
