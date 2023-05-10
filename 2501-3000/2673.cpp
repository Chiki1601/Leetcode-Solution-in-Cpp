class Solution {
public:
    int dfs(int n,vector<int> &cost,int i,int &ans) {
        if(i > n) return 0;
        int leftCost = dfs(n,cost,2 * i,ans);
        int rightCost = dfs(n,cost,2 * i + 1,ans);
        ans += abs(leftCost - rightCost);
        return max(leftCost,rightCost) + cost[i - 1];
    }
    int minIncrements(int n, vector<int>& cost) {
        int ans = 0;
        dfs(n,cost,1,ans);
        return ans;
    }
};
