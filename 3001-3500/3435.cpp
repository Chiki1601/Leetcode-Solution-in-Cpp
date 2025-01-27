class Solution {
public:
    vector<vector<int>> supersequences(vector<string>& words) {
        // Step 1: Map characters to indices
        bool used[26] = {};
        for (auto& w : words) 
            for (char c : w) 
                used[c - 'a'] = true;

        vector<int> charMap(26, -1);
        vector<char> chars;
        int charCount = 0;
        for (int c = 0; c < 26; c++) {
            if (used[c]) {
                charMap[c] = charCount++;
                chars.push_back('a' + c);
            }
        }

        // Step 2: Build graph and detect self-loops
        vector<vector<bool>> graph(charCount, vector<bool>(charCount));
        vector<bool> selfLoop(charCount);
        for (auto& w : words) {
            int u = charMap[w[0] - 'a'], v = charMap[w[1] - 'a'];
            if (u == v) selfLoop[u] = true;
            else graph[u][v] = true;
        }

        // Step 3: Find SCCs using Tarjan's algorithm
        vector<int> disc(charCount, -1), low(charCount), comp(charCount, -1);
        vector<bool> inStack(charCount);
        stack<int> stk;
        int time = 0, sccTotal = 0;

        function<void(int)> tarjan = [&](int u) {
            disc[u] = low[u] = time++;
            stk.push(u); inStack[u] = true;
            for (int v = 0; v < charCount; v++) {
                if (!graph[u][v]) continue;
                if (disc[v] == -1) {
                    tarjan(v);
                    low[u] = min(low[u], low[v]);
                } else if (inStack[v]) {
                    low[u] = min(low[u], disc[v]);
                }
            }
            if (low[u] == disc[u]) {
                while (true) {
                    int v = stk.top(); stk.pop();
                    inStack[v] = false; comp[v] = sccTotal;
                    if (v == u) break;
                }
                sccTotal++;
            }
        };

        for (int i = 0; i < charCount; i++)
            if (disc[i] == -1) tarjan(i);

        // Step 4: Group SCCs and build DAG
        vector<vector<int>> sccGroups(sccTotal);
        for (int i = 0; i < charCount; i++)
            sccGroups[comp[i]].push_back(i);

        vector<vector<int>> sccGraph(sccTotal);
        vector<int> inDegree(sccTotal);
        for (int u = 0; u < charCount; u++) {
            for (int v = 0; v < charCount; v++) {
                if (graph[u][v] && comp[u] != comp[v]) {
                    sccGraph[comp[u]].push_back(comp[v]);
                    inDegree[comp[v]]++;
                }
            }
        }

        // Step 5: Topological sort of SCCs
        queue<int> q;
        vector<int> topoOrder;
        for (int i = 0; i < sccTotal; i++)
            if (inDegree[i] == 0) q.push(i);

        while (!q.empty()) {
            int u = q.front(); q.pop();
            topoOrder.push_back(u);
            for (int v : sccGraph[u]) 
                if (--inDegree[v] == 0) q.push(v);
        }

        // Step 6: Find minimal feedback vertex sets for each SCC
        auto findMinFVS = [&](const vector<vector<bool>>& g, int n) {
            set<vector<int>> patterns;
            for (int mask = 0; mask < (1 << n); mask++) {
                vector<bool> removed(n);
                for (int i = 0; i < n; i++)
                    if (mask & (1 << i)) removed[i] = true;

                // Check if removing these nodes makes the graph acyclic
                vector<int> deg(n);
                for (int u = 0; u < n; u++) {
                    if (removed[u]) continue;
                    for (int v = 0; v < n; v++) 
                        if (!removed[v] && g[u][v]) deg[v]++;
                }

                queue<int> q; int cnt = 0;
                for (int i = 0; i < n; i++) 
                    if (!removed[i] && deg[i] == 0) q.push(i);

                while (!q.empty()) {
                    int u = q.front(); q.pop(); cnt++;
                    for (int v = 0; v < n; v++) 
                        if (!removed[v] && g[u][v] && --deg[v] == 0) q.push(v);
                }

                if (cnt == n - __builtin_popcount(mask)) {
                    vector<int> freq(n, 1);
                    for (int i = 0; i < n; i++)
                        if (mask & (1 << i)) freq[i] = 2;
                    patterns.insert(freq);
                }
            }
            return vector<vector<int>>(patterns.begin(), patterns.end());
        };

        vector<vector<vector<int>>> sccPatterns(sccTotal);
        for (int i = 0; i < sccTotal; i++) {
            auto& group = sccGroups[i];
            if (group.size() == 1) {
                sccPatterns[i] = selfLoop[group[0]] ? vector<vector<int>>{{2}} : vector<vector<int>>{{1}};
                continue;
            }

            vector<vector<bool>> subgraph(group.size(), vector<bool>(group.size()));
            for (int j = 0; j < group.size(); j++) {
                if (selfLoop[group[j]]) subgraph[j][j] = true;
                for (int k = 0; k < group.size(); k++)
                    if (graph[group[j]][group[k]]) subgraph[j][k] = true;
            }
            sccPatterns[i] = findMinFVS(subgraph, group.size());
        }

        // Step 7: Combine patterns across SCCs
        vector<vector<int>> result = {{}};
        for (int scc : topoOrder) {
            vector<vector<int>> newResult;
            for (auto& freq : result) {
                for (auto& pattern : sccPatterns[scc]) {
                    vector<int> newFreq = freq;
                    newFreq.resize(charCount);
                    for (int i = 0; i < sccGroups[scc].size(); i++) 
                        newFreq[sccGroups[scc][i]] = pattern[i];
                    newResult.push_back(newFreq);
                }
            }
            result = move(newResult);
        }

        // Step 8: Deduplicate and format output
        set<vector<int>> uniqueFreqs;
        for (auto& freq : result) {
            vector<int> finalFreq(26);
            for (int i = 0; i < charCount; i++)
                finalFreq[chars[i] - 'a'] = freq[i];
            uniqueFreqs.insert(finalFreq);
        }

        return vector<vector<int>>(uniqueFreqs.begin(), uniqueFreqs.end());
    }
};
