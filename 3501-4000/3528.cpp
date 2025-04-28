class Solution {
public:
    vector<int> baseUnitConversions(vector<vector<int>>& conversions) {
        int n = conversions.size();
        vector<vector<pair<int, int>>> graph(n + 1);
        vector<int> res(n + 1, 1);
        for (auto& conversion : conversions){
            graph[conversion[0]].push_back({conversion[1], conversion[2]});
        }
        stack<pair<int, int>> stack;
        stack.push({0, 1});
        while (!stack.empty()){
            auto [source, prev] = stack.top(); stack.pop();
            for (auto& [target, fac] : graph[source]){
                res[target] = ((long long)res[target] * prev * fac) % 1000000007;
                stack.push({target, res[target]});
            }
        }
        return res;
    }
};
