class Solution {
public:
    vector<int> minCosts(vector<int>& cost) {
        partial_sum(cost.begin(), cost.end(), cost.begin(), [](int x,  int y){return x=min(x, y);});
        return cost;
    }
};
