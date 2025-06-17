class LCAFinder {
private:
    int n;
    vector<vector<int>> tree;
    vector<int> euler, depth, first;
    vector<vector<int>> st;
    vector<int> LOG;

    void dfs(int node, int d, int parent) {
        first[node] = euler.size();
        euler.push_back(node);
        depth.push_back(d);
        for (int child : tree[node]) {
            if (child != parent) {
                dfs(child, d + 1, node);
                euler.push_back(node);
                depth.push_back(d);
            }
        }
    }

    void buildSparseTable() {
        int m = depth.size();
        int logLen = LOG[m] + 1;
        st.assign(logLen, vector<int>(m));

        for (int i = 0; i < m; ++i)
            st[0][i] = i;

        for (int k = 1; (1 << k) <= m; ++k) {
            for (int i = 0; i + (1 << k) <= m; ++i) {
                int x = st[k - 1][i];
                int y = st[k - 1][i + (1 << (k - 1))];
                st[k][i] = (depth[x] < depth[y] ? x : y);
            }
        }
    }

public:
    LCAFinder(int nodes) : n(nodes) {
        tree.resize(n + 1);
        first.resize(n + 1);
        LOG.resize(2 * n + 1);
        for (int i = 2; i <= 2 * n; ++i)
            LOG[i] = LOG[i / 2] + 1;
    }

    void addEdge(int u, int v) {
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    void preprocess(int root = 1) {
        dfs(root, 0, -1);
        buildSparseTable();
    }

    int getLCA(int u, int v) {
        int l = first[u], r = first[v];
        if (l > r) swap(l, r);
        int k = LOG[r - l + 1];
        int x = st[k][l];
        int y = st[k][r - (1 << k) + 1];
        return (depth[x] < depth[y] ? euler[x] : euler[y]);
    }
};

class Solution {
public:
    void assignsum(int node, int par, vector<vector<pair<int,int>>>& adj, vector<long long>& prefsum, long long sum)
    {
        prefsum[node]=sum;
        for(auto j:adj[node])
        {
            if(j.first!=par)
            {
                assignsum(j.first,node,adj,prefsum,sum+j.second);
            }
        }
        return;
    }
    int binarysearch0(vector<int>& path, double dist, vector<long long>& prefsum)
    {
        dist/=2;
        int left=0,right=path.size()-1,node=path.back();
        while(left<=right)
        {
            int mid=(left+right)/2;
            if((prefsum[node]-prefsum[path[mid]])<dist)
            {
                right=mid-1;
            }
            else
            {
                left=mid+1;
            }
        }
        return path[right];
    }
    int binarysearch1(vector<int>& path, double dist, vector<long long>& prefsum)
    {
        dist/=2;
        int left=0,right=path.size()-1,node=path.back();
        while(left<=right)
        {
            int mid=(left+right)/2;
            if((prefsum[node]-prefsum[path[mid]])<=dist)
            {
                right=mid-1;
            }
            else
            {
                left=mid+1;
            }
        }
        return path[right+1];
    }
    void answerstuff(int node, int par, vector<vector<pair<int,int>>>& adj, vector<long long>& prefsum, vector<vector<vector<long long>>>& offlinequery, vector<int>& path, vector<int>& ans)
    {
        path.push_back(node);
        for(auto j:offlinequery[node])
        {
            long long idx=j[0],dist=j[1],type=j[2];
            if(type)
            {
                ans[idx]=binarysearch1(path,(double)dist,prefsum);
            }
            else
            {
                ans[idx]=binarysearch0(path,(double)dist,prefsum);
            }
        }
        for(auto j:adj[node])
        {
            if(j.first!=par)
            {
                answerstuff(j.first,node,adj,prefsum,offlinequery,path,ans);
            }
        }
        path.pop_back();
        return;
    }
    vector<int> findMedian(int n, vector<vector<int>>& edges, vector<vector<int>>& queries) {
        LCAFinder lca(n);
        for(auto j:edges)
        {
            lca.addEdge(j[0], j[1]);
        }
        vector<vector<pair<int,int>>>adj(n,vector<pair<int,int>>());
        for(auto j:edges)
        {
            adj[j[0]].push_back({j[1],j[2]});
            adj[j[1]].push_back({j[0],j[2]});
        }
        vector<int>ans(queries.size(),-1);
        vector<long long>prefsum(n,0);
        vector<vector<vector<long long>>>offlinequery(n,vector<vector<long long>>());
        assignsum(0,-1,adj,prefsum,0ll);
        lca.preprocess(0);
        for(int i=0;i<queries.size();i++)
        {
            int par=lca.getLCA(queries[i][0],queries[i][1]);
            long long dist=prefsum[queries[i][0]]+prefsum[queries[i][1]]-(2*prefsum[par]);
            if((prefsum[queries[i][0]]-prefsum[par])>=(((double)dist)/2))
            {
                offlinequery[queries[i][0]].push_back({i,dist,0});
            }
            else
            {
                offlinequery[queries[i][1]].push_back({i,dist,1});
            }
        }
        vector<int>path;
        answerstuff(0,-1,adj,prefsum,offlinequery,path,ans);
        return ans;
    }
};
