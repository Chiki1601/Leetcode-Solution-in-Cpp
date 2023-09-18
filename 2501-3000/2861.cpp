class Solution {
private:
    bool isPossible(int n, int k, int budget, vector<vector<int>> &composition, vector<int> &stock, 
                    vector<int> &costs, int fixed_alloy) {
        
        for (int i = 0; i < k; i++) {
            long long calBudget = 0;
            for (int j = 0; j < n; j++) {
                // this much quantity of jth metal is required to form the "fixed_alloy";
                long long required = 1LL*composition[i][j]*fixed_alloy;
                // subtracting the stocked portion of the jth metal;
                required -= stock[j];
                if (required > 0) {
                    // adding the cost for required quantity of jth metal to form the "fixed_alloy";
                    calBudget += 1LL*required*costs[j];
                }
            }
            // "fixed alloy can be formed with the jth machine";
            if (calBudget <= 1LL*budget) return true;
        }
        
        // can't be formed with any of the machine;
        return false;
    }
public:
    int maxNumberOfAlloys(int n, int k, int budget, vector<vector<int>> &composition, vector<int> &stock, vector<int> &cost) {
        
        int low = 1, high = 1e9;
        int ans = 0; // intialise the ans = 0;

        while (low <= high) {
            int mid = low + (high-low)/2;
            if (isPossible(n, k, budget, composition, stock, cost, mid)) {
                low = mid + 1;
                ans = mid; // we can form the "mid" quantity of alloys from any of the compositions in the given "budget";
            } else {
                high = mid - 1;
            }
        }

        return ans;
    }
};
