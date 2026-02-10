using ll = long long;

class Solution {
    struct Line { 
        ll slope, intercept; 
        int partitionCount;         
        ll eval(ll x) { return slope * x + intercept; } 
    };
    bool isRedundant(const Line& prev, const Line& middle, const Line& next) {
        return (__int128)(next.intercept - prev.intercept) * (prev.slope - middle.slope) 
            <= (__int128)(middle.intercept - prev.intercept) * (prev.slope - next.slope);
    }
    pair<ll, int> solveWithPenalty(int n, const vector<ll>& P, ll lambda) {
        deque<Line> hullDeque;
        
        hullDeque.push_back({0, 0, 0});
        
        ll currentVal = 0; 
        int currentCount = 0;
        
        for (int i = 1; i <= n; ++i) {
            ll x = P[i];
            
            while (hullDeque.size() > 1 && hullDeque[0].eval(x) >= hullDeque[1].eval(x)) {
                hullDeque.pop_front();
            }
            ll bestPrevVal = hullDeque[0].eval(x);
            currentVal = (x * x) + x + 2 * lambda + bestPrevVal;
            currentCount = hullDeque[0].partitionCount + 1;
            
            ll newSlope = -2 * x;
            ll newIntercept = currentVal + (x * x) - x;
            Line newLine = {newSlope, newIntercept, currentCount};
            while (hullDeque.size() > 1 && isRedundant(hullDeque[hullDeque.size() - 2], hullDeque.back(), newLine)) {
                hullDeque.pop_back();
            }
            hullDeque.push_back(newLine);
        }
        
        return {currentVal, currentCount};
    }

public:
    long long minPartitionScore(vector<int>& nums, int k) {
        int n = nums.size();
        vector<ll> prefixSum(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            prefixSum[i + 1] = prefixSum[i] + nums[i];
        }
        
        ll low = 0, high = 2e15; 
        ll bestLambda = 0;
       
        while (low <= high) {
            ll mid = low + (high - low) / 2;
             if (solveWithPenalty(n, prefixSum, mid).second <= k) {
                bestLambda = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }      
        return (solveWithPenalty(n, prefixSum, bestLambda).first - 2LL * k * bestLambda) / 2;
    }
};
