class Solution {
public:
    void bellman(unordered_map<string, double>& best, vector<vector<string>>& pairs, vector<double>& rates){
        for(int relax_iteration = 0; relax_iteration < pairs.size(); ++relax_iteration){
            for(int i = 0; i < pairs.size(); ++i){
                best[pairs[i][1]] = max(best[pairs[i][1]], best[pairs[i][0]]*rates[i]);
                best[pairs[i][0]] = max(best[pairs[i][0]], best[pairs[i][1]]/rates[i]);
            }
        } 
    }

    double maxAmount(string initialCurrency, vector<vector<string>>& pairs1, vector<double>& rates1, vector<vector<string>>& pairs2, vector<double>& rates2) {
        unordered_map<string, double> best;
        best[initialCurrency] = 1;
        bellman(best, pairs1, rates1);
        bellman(best, pairs2, rates2);
        return best[initialCurrency]; 
    }
};
