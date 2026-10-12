class Solution {
public:
    int minInversions(vector<string>& words, vector<int>& target) {
        int n = words.size();
        struct Node {
            int ch[10];
            int idx;
            Node() : idx(-1) { fill(ch,ch+10,-1);}
        };
        vector<int> pos(n);
        for(int i =0; i<n; ++i)
        {
            pos[target[i]] =i;
        }
        vector<Node> t;
        t.emplace_back();
        for(int i =0; i<n;++i)
        {
            int cur = 0;
            for(char c: words[i])
            {
                int d=c-'a';
                if(t[cur].ch[d]==-1)
                {
                    int id = t.size();
                    t.emplace_back();
                    t[cur].ch[d]=id;
                }
                cur = t[cur].ch[d];
            }
            t[cur].idx = i;
        }
        long long total = 0;
        function<vector<int>(int)>dfs = [&](int u)-> vector<int>{
            vector<vector<int>> cs;
            for(int c =0; c<10;++c)
            {
                if(t[u].ch[c]!=-1) cs.push_back(dfs(t[u].ch[c]));
            }
            int k = cs.size();

            if(t[u].idx !=-1)
            {
                int p = pos[t[u].idx];
                for(auto& v:cs)
                {
                    total+= lower_bound(v.begin(),v.end(),p)-v.begin();
                }
            }
            vector<vector<long long>>cost(k,vector<long long>(k,0));
            for(int i =0; i<k;++i)
            {
                for(int j =0; j<k;++j)
                {
                    if(i==j) continue;
                    size_t ptr = 0;
                    long long c=0;
                    for(int x: cs[i]){
                        while(ptr<cs[j].size()&&cs[j][ptr]<x)++ptr;
                        c+=ptr;
                    }
                    cost[i][j]=c;
                }
            }
            const long long INF = LLONG_MAX/4;
            vector<long long>dp (1<<k,INF);
            dp[0]=0;
            for(int mask =0;mask<(1<<k);++mask)
            {
                if(dp[mask]==INF)continue;
                for(int j =0; j<k;++j)
                {
                    if(mask>>j & 1)continue;
                    long long add =0;
                    for(int m =0; m<k;++m)
                    {
                        if(mask>>m &1) add += cost[m][j];
                    }
                    int nm = mask | (1<<j);
                    dp[nm]=min(dp[nm],dp[mask]+add);
                }
            }
            total += dp[(1<<k)-1];

            vector<int> res;
            if(t[u].idx!=-1)res.push_back(pos[t[u].idx]);
            for(auto& v:cs) res.insert(res.end(),v.begin(),v.end());
            sort(res.begin(),res.end());
            return res;
        };
        dfs(0);
        return (int)total;
    }
};
