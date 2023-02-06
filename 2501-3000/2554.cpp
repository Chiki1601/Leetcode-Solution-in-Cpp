class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        int maxi = 0;
        int sum = 0;
        
        // store banned indexes
        set<int> st;
        for( auto &it : banned ) st.insert( it );
        
        for( int i=1 ; i<=n ; i++ ){
            
            // indexes wihch are not in banned array 
            // take them, keeping the sum lesser than the maximum Sum 
            
            if( st.count(i) == 0 && ((sum+i) <= maxSum )) {
                sum += i;
                maxi++;
            }
        }
        
        return maxi;
    }
};
