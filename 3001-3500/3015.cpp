class Solution {
public:
    vector<int> countOfPairs(int n, int x, int y) {
        // to make sure that x<=y in every case
        if(x>y)
            return countOfPairs(n, y, x);
        
        vector<int> res(n, 0);
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<i;j++){
                int idx = i-j;          
                idx = min(idx, abs(j-x) + 1 + abs(i-y));
                if(idx>=1)
                    res[idx-1]+=2;  // add 2 as we can go from j->i and i->j
            }
        }
        return res;
        
    }
};
