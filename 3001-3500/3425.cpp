class Solution {
public:
    int maxL = 0;
    int nodes = 1;

    void help(vector<pair<int, int>> &a, vector<int> &b){
        int l = 0, n = b.size();
        vector<int> s(50001, 0);
        s[b[a[0].first]] = 1;
        for(int r = 1; r<a.size(); r++){
            pair<int,int > t = a[r];
            int i = t.first;
            int v = b[i];
            while(s[v] > 0){
                s[(b[a[l++].first])]--;
            }
            s[v] = 1;
            if(a[r].second - a[l].second > maxL){
                maxL = a[r].second - a[l].second;
                nodes = r - l + 1;
            }
            else if(a[r].second - a[l].second == maxL){
                nodes = min(nodes, r- l + 1);
            }
        }
    }

    void dfs(vector<vector<pair<int, int>>>& g,  vector<int> &b, vector<pair<int, int>> &a, int par){
        pair<int, int> t = a.back();
        int u = t.first, l = t.second;
        bool isLeaf = true;
        for(int i=0; i<g[u].size(); i++){
            if(g[u][i].first != par){
                isLeaf = false;
                a.push_back({g[u][i].first, g[u][i].second + l});
                dfs(g, b, a, u);
                a.pop_back();
            }
        }

        if(isLeaf){
            help(a, b);
        }
    }

    vector<int> longestSpecialPath(vector<vector<int>>& e, vector<int>& a) {
        int n = a.size();
        vector<vector<pair<int, int>>> g(n);
        for(vector<int> &t: e){
            g[t[0]].push_back({t[1], t[2]});
            g[t[1]].push_back({t[0], t[2]});
        }
        vector<pair<int, int>> temp;
        temp.push_back({0, 0});
        dfs(g, a, temp, -1);
        return {maxL, nodes};
    }
};
