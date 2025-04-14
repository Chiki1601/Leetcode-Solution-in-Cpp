class Solution {
public:

    // (Strikingly similar to this problem) - Path Queries
    // https://cses.fi/problemset/task/1138/

    unordered_map<int,vector<pair<int,int>>> graph;
    vector<int> st, ed, currParent, value;

    void EulerTour(int node,int par,int &idx){
        st[node]=idx;
        currParent[node]=par;
        for(auto &[nbr,wt]:graph[node]){
            if(nbr==par) continue;
            idx++;
            value[nbr]=wt;
            EulerTour(nbr,node,idx);
        }
        ed[node]=idx;
    }
 
    struct SegTree {
    public:
    
        SegTree (int _n) : n (_n) {
            tree.resize(4*n, 0);
        }
        
        int query (int x, int y) {
            return query (x, y, 0, n-1, 0);
        }
        
        void update (int ind, int val) {
            update (ind, val, 0, n-1, 0);
        }
    
    private:
        
        vector<int> tree;
        int n;
        
        int query (int x, int y, int l, int r, int i) {
            if (r < x || l > y) return 0;
            if (l >= x && r <= y) return tree[i];
            
            int m = (l+r) >> 1;
            return (
                query (x, y, l, m, i*2+1) +
                query (x, y, m+1, r, i*2+2)
            );
        }
        
        void update (int ind, int val, int l, int r, int i) {
            if (l == r) {
                tree[i] += val;
                return;
            }
            
            int m = (l+r) >> 1;
            if (m >= ind) update (ind, val, l, m, i*2+1);
            else update (ind, val, m+1, r, i*2+2);
            
            tree[i] = tree[i*2+1] + tree[i*2+2];
        }
    };

    vector<int> treeQueries(int n, vector<vector<int>>& edges, vector<vector<int>>& queries) {
        st.resize(n); ed.resize(n); currParent.resize(n); value.resize(n,0);
        for(auto &edge:edges){
            int u=edge[0], v=edge[1], wt=edge[2];
            u--; v--;
            graph[u].push_back({v,wt});
            graph[v].push_back({u,wt});
        }

        int idx=0;
        EulerTour(0,-1,idx); // tree is rooted at node 1

        SegTree tree(idx+2);

        for(int i=1;i<n;++i){
            int stIdx=st[i], edIdx=ed[i];
            tree.update(stIdx,value[i]);
            if(edIdx+1<=idx) tree.update(edIdx+1,-value[i]);
        }

        vector<int> ans;

        for(auto &q:queries){
            int type=q[0];
            if(type==1){ // update
                int u=q[1], v=q[2], newWt=q[3];
                u--; v--;
                if(currParent[v]==u){
                    swap(u,v); // we're assuming that v will be parent of u
                }
                // Range Update in Segment Tree , the change in "weight"
                // delta = q[3] - value[st[child]] 
                // we add this value at st[child]
                // and subtract at ed[child] + 1 
                int stIdx=st[u], edIdx=ed[u], currWt=value[u];
                tree.update(stIdx,newWt-currWt);
                tree.update(edIdx+1,currWt-newWt);
                value[u]=newWt;
            }
            else{ // answer
                int node=q[1];
                node--;
                ans.push_back(tree.query(0,st[node]));
            }
        }

        return ans;
    }
};
