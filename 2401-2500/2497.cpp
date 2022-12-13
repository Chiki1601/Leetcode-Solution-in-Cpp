class Solution {
public:
    int maxStarSum(vector<int>& vals, vector<vector<int>>& edges, int k) {
        int X = 1e5+10;
        vector<int>adj[X];
        for(auto x:edges)
        {
            int a = x[0];
            int b = x[1];
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        map<int,vector<int>>mp;// Store the connected nodes of each index to calculate first k maximum values for each one
        for(int i=0;i<vals.size();i++)
        {
            for(auto x:adj[i])
            {
                mp[i].push_back(vals[x]);
            }
        }
        int ans = INT_MIN;
        for(int i=0;i<vals.size();i++)
        {
            auto &x = mp[i];
            sort(x.rbegin(),x.rend());// Sort and reverse the array
            int sum = 0;
            int maxi = 0;
            for(int j=0;j<min(k,(int)x.size());j++)// Take the first maximum k elements
            {
                sum+=x[j];
                maxi = max(maxi,sum);// In case the sum is negative or getting decreased then we will not consider those values like 5 4 3 -2 -1 then -2 and -1 will not be considered as they are decreasing the maximum sum
            }
            maxi+=vals[i];// Must add the value of the index because it is the center
            ans = max(ans,maxi);
        }
        return ans;
    }
};
