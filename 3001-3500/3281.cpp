class Solution {
    
    bool isPossible(vector<int> &start, int diff, long long d) {
        int n = start.size();
        long long l = start[0];
        for(int i=1;i<n;i++) {
            if( l + diff > start[i] + d) {
                return false;
            }
            l = max(l + diff,(long long) start[i]);
        }
        return true;
    }
    
public:
    int maxPossibleScore(vector<int>& start, int d) {
        sort(start.begin(), start.end());
        int n = start.size();
        int l = 0;
        int r = 2e9;
        while(l<=r) {
            int m = l+(r-l)/2;
            if(isPossible(start, m, d)) {
                l = m+1;
            } else {
                r = m-1;
            }
        }
        return r;
    }
};
