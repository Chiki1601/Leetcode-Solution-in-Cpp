#define ll long long

class Solution {
public:
    vector<bool> findAnswer(int n, vector<vector<int>>& e) {
        
        vector<vector< pair< ll, ll> > > adj;
        adj.resize(n);
        
        pair<ll, ll > p;
        vector<bool> res(e.size(), false);
        
        
        for(int i=0; i<e.size(); ++i)
        {
            int u = e[i][0];
            int v = e[i][1];
            
            int wt = e[i][2];
            
            adj[u].push_back({v,wt});
            adj[v].push_back({u, wt});
        }
        
        vector<ll> d1(n,1e12);
        vector<ll> d2(n,1e12);
        
        priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<>> pq1;
        priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<>> pq2;
        
        pq1.push({0, 0});
        d1[0] = 0;
        
        while(!pq1.empty())       // Dijkstra's from vertex 0
        {
            p = pq1.top(); pq1.pop();
            ll curr = p.second;
            ll dist = p.first;

            if(dist > d1[curr])
                continue;

            for(int i=0; i<adj[curr].size(); ++i)
            {
                ll next = adj[curr][i].first;
                ll wt = adj[curr][i].second;

                if(dist + wt < d1[next])
                {
                    d1[next] = dist + wt;
                    pq1.push({d1[next], next});
                }
            }
        }
        
        pq2.push({0, n-1});
        d2[n-1] = 0;
        
        while(!pq2.empty())       // Dijkstra's from vertex N-1   
        {
            p = pq2.top(); pq2.pop();
            ll curr = p.second;
            ll dist = p.first;

            if(dist > d2[curr])
                continue;

            for(int i=0; i<adj[curr].size(); ++i)
            {
                ll next = adj[curr][i].first;
                ll wt = adj[curr][i].second;

                if(dist + wt < d2[next] )
                {
                    d2[next] = dist + wt;
                    pq2.push({d2[next], next});
                }
            }
        }
        
        
        for(int i=0; i<e.size(); ++i) // checking the condition for each edge
        {
            int u = e[i][0];
            int v = e[i][1];
            
            int wt = e[i][2];
            
            if(d1[u] + d2[v] + wt == d1[n-1])
                res[i] = true;
            
            if(d1[v] + d2[u] + wt == d1[n-1])
                res[i] = true;
        }
        
        return res;
    }
};
