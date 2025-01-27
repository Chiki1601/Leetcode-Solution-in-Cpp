class Solution {
public:
    const int n = 26;
    vector<vector<int>> es;
    int ans = n * 2;
    vector<int> d;
    vector<int> ind;
    vector<int> outd;
    vector<vector<int>> res;

    int getindex(int y, int dy)
    {
        if (dy == 2) return y + n;
        return y;
    }

    bool top(vector<int>& cnt, int tt)
    {
        for (int i = 0; i < n + n; i++) d[i] = 0;
        for (auto& e : es)
            for (auto y : e)
                d[getindex(y, cnt[y])]++;

        int cur = tt;
        deque<int> q;
        for (int i = 0; i < n; i++)
        {
            if (cnt[i] == 0) continue;
            int j = i + n;
            if (d[i] == 0) q.push_back(i);
            if (cnt[i] == 2 && d[j] == 0) q.push_back(j);
        }

        while (!q.empty())
        {
            auto c = q.front();
            q.pop_front();
            cur--;
            if (c >= n) continue;
            int x = c;
            for (auto& y1 : es[x])
            {
                int y = getindex(y1, cnt[y1]);
                d[y]--;
                if (d[y] == 0) q.push_back(y);
            }
        }
        return (cur == 0);
    }

    void dfs(int i, vector<int>& cnt, int t)
    {
        if (i >= cnt.size())
        {
            if (t > ans) return;
            bool valid = top(cnt, t);
            if (valid == false) return;
            if (t < ans)
            {
                ans = t;
                res.clear();
            } 
            res.push_back(cnt);
            return;
        }
        int cur = cnt[i];
        int mx = 0;
        if (ind[i] > 0) mx++;
        if (outd[i] > 0) mx++;
        if (mx == 0) return dfs(i + 1, cnt, t);
        for (int j = 1; j <= mx; j++) 
        {
            cnt[i] = j;
            dfs(i + 1, cnt, t + j);
        }
        cnt[i] = cur;
        return;
    }
    
    vector<vector<int>> supersequences(vector<string>& ws) {
        ind = vector<int>(n, 0);
        outd = vector<int>(n, 0);
        d = vector<int>(n * 2, 0);
        es.resize(n);
        for (auto& w : ws)
        {
            int x = w[0] - 'a';
            int y = w[1] - 'a';
            outd[x]++;
            ind[y]++;
            es[x].push_back(y);
        }
        vector<int> cnt(n, 0);
        dfs(0, cnt, 0);
        return res;
    }
};
