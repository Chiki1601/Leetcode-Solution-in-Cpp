class Solution {
    vector<int> newInd;
    vector<int> group;
    vector<vector<int>> dp;
    vector<int> steps;
public:
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<pair<int, int>> numWithInd; 
        for(int i=0; i<n; ++i){
            numWithInd.push_back({nums[i], i});
        }
        sort(numWithInd.begin(), numWithInd.end());
        newInd.resize(n);
        for(int i=0; i<n; ++i){
            newInd[numWithInd[i].second] = i;
        }

        int g = 0;
        group.resize(n);
        for(int i=1; i<n; ++i){
            if(numWithInd[i].first - numWithInd[i-1].first > maxDiff) 
                ++g;
            group[i] = g;
        }

        dp.resize(17, vector<int>(n, 0));
        steps.resize(17);
        steps[0] = 1;
        int r = 0;
        for(int i=0; i<n; ++i){
            while(r < n && numWithInd[r].first - numWithInd[i].first <= maxDiff){
                ++r;
            }
            dp[0][i] = r-1; 
        }
        for(int row = 1; row < 17; ++row){
            steps[row] = steps[row-1] * 2;
            for(int i=0; i<n; ++i){
                dp[row][i] = dp[row-1][dp[row-1][i]];
            }
        }

        vector<int> result;
        result.reserve(queries.size());
        for(auto& q : queries){
            if( group[newInd[q[0]]] != group[newInd[q[1]]])
                result.push_back(-1);
            else{
                int ind1 = newInd[q[0]];
                int ind2 = newInd[q[1]];
                if(ind2 < ind1) swap(ind1, ind2); 
                if(ind1 == ind2){
                    result.push_back(0);
                    continue;
                }
                int step = 0;
                int cur = ind1;
                for(int i=16; i>=0; --i){
                    if(dp[i][cur] < ind2){
                        cur = dp[i][cur];
                        step += steps[i];
                    }
                }
                result.push_back(step+1);
            }
        }
        return result;
    }
};
