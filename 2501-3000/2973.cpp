class Solution {
public:
 
vector<long long> ans;

vector<long long> dfs(vector<vector<int>>& t, vector<int>& cost, int root, int par){
    vector<long long> usefulCost = {cost[root]};
    for(auto n: t[root]){
        if(n == par) continue;
        vector<long long> v = dfs(t, cost, n, root);  //go deep into the leaf nodes first 
        for(auto e: v) usefulCost.push_back(e);  //accumulate all the cost from all its child node at root level
    }

    // After traversing all sub tree, sort the cost accumulated
    sort(usefulCost.begin(), usefulCost.end(), greater<long long>());
    long long sz = usefulCost.size();
                                                                                        
    if(usefulCost.size() < 3) { ans[root] = 1; return usefulCost; }  // check if the size of the sub tree less than 3 then set cost to 1 and return from here.
    if(usefulCost[1] * usefulCost[2] > usefulCost[sz - 1] * usefulCost[sz -2]) {   // check if the product of the 2nd larget and 3rd larget is greater than smallest two numbers ( as two smaller values are negative and after multiplication they may give larger vlaues)
        ans[root] = usefulCost[0] * usefulCost[1] * usefulCost[2];  
    }
    else {
        ans[root] = usefulCost[0] * usefulCost[sz - 1] * usefulCost[sz - 2];   
    }
    if(ans[root] < 0) ans[root] = 0;
    if(usefulCost.size() <= 5) return usefulCost;
    return {usefulCost[0], usefulCost[1], usefulCost[2], usefulCost[sz-2], usefulCost[sz-1]};   //return largest 3 and smallest two items, only those can be useful in later on step and discard others.
}

vector<long long> placedCoins(vector<vector<int>>& edges, vector<int>& cost) {
    ans.resize(cost.size(), 0); 
    vector<vector<int>> t(cost.size());
    for(auto e : edges){ t[e[0]].push_back(e[1]); t[e[1]].push_back(e[0]); }
    dfs(t, cost, 0, -1);
    return ans;
}
};
