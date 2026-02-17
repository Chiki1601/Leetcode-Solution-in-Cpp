class SegmentTree {
public:
	int n;
	vector<int> segTree;

	SegmentTree (vector<int>& nums) {
		n = nums.size();
		segTree.resize(4 * n);

		buildSegTree(0, 0, n - 1, nums);
	}

	void buildSegTree (int i, int l, int r, vector<int>& nums) {
		if (l == r) {
			segTree[i] = nums[l];
			return;
		}

		int mid = (l + r) / 2;
		buildSegTree(2 * i + 1, l, mid, nums);
		buildSegTree(2 * i + 2, mid + 1, r, nums);

		segTree[i] = (segTree[2 * i + 1] ^ segTree[2 * i + 2]);
	}	

	void update (int i, int idx, int l, int r, int val) {
		if (l == r) {
			segTree[i] = val;
			return;
		}

		int mid = (l + r) / 2;
		if (idx <= mid) {
			update(2 * i + 1, idx, l, mid, val);
		} else {
			update(2 * i + 2, idx, mid + 1, r, val);
		}

		segTree[i] = (segTree[2 * i + 1] ^ segTree[2 * i + 2]);
	}

	int Query (int i, int start, int end, int l, int r) {
		if (r < start || l > end) {
			return 0;
		}

		if (l >= start && r <= end) {
			return segTree[i];
		}

		int mid = (l + r) / 2;
		return Query(2 * i + 1, start, end, l, mid) ^ Query(2 * i + 2, start, end, mid + 1, r);
	}
};

class Solution {
public:

    vector<int> in, out;
    vector<int> euler;
    vector<int> depth;
    vector<vector<int>> adj;

    // keep track for parent nodes using binary lifting
    vector<vector<int>> parent;

    string s;
    int timer = 0;

    // euler tour
    void eulerDFS (int node, int parent) {
        euler[timer] = (1 << (s[node] - 'a'));
        in[node] = timer++;

        for (int child: adj[node]) {
            if (child == parent) continue;
            eulerDFS(child, node);
        }

        euler[timer] = (1 << (s[node] - 'a'));
        out[node] = timer++;
    }

    // finding parent node using binay lifting
    void dfs (int node, int prev, int d) {
        parent[node][0] = prev;
        depth[node] = d;

        for (int i = 1; i < 20; i++) {
            parent[node][i] = parent[parent[node][i - 1]][i - 1];
        }

        for (int child: adj[node]) {
            if (child == prev) continue;
            dfs(child, node, d + 1);
        }
    }

    // Check if y is in subtree of x
    bool isAncestor (int x, int y) {
        return in[y] >= in[x] && out[x] >= out[y]; 
    }

    // find LCA
    int LCA (int u, int v) {
        if (isAncestor(u, v)) return u;
        if (isAncestor(v, u)) return v;

        if (depth[u] < depth[v]) {
            swap(u, v);
        }

        for (int i = 19; i >= 0; i--) {
            if ((depth[u] - depth[v]) & (1 << i)) {
                u = parent[u][i];
            }
        }

        if (u == v) {
            return u;
        }

        for (int i = 19; i >= 0; i--) {
            if (parent[u][i] != parent[v][i]) {
                u = parent[u][i];
                v = parent[v][i];
            }
        }

        return parent[u][0];
    }

    vector<bool> palindromePath(int n, vector<vector<int>>& edges, string _s, vector<string>& queries) {
        in.resize(n + 1); 
        out.resize(n + 1);
        adj.resize(n + 1);
        euler.resize(2 * n);
        depth.resize(n + 1);
        parent.assign(n, vector<int> (21, 0));
        s = _s;

        for (auto &edge: edges) {
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        eulerDFS(0, -1);

        dfs(0, 0, 0);

        SegmentTree seg(euler);
        vector<bool> ans;

        for (auto &query: queries) {
            stringstream ss(query);

            string type;
            int a, b;
            char c;

            ss >> type >> a;
            if (type == "update") {
                ss >> c;

                seg.update(0, in[a], 0, 2 * n - 1, (1 << (c - 'a')));
                seg.update(0, out[a], 0, 2 * n - 1, (1 << (c - 'a')));
                
                s[a] = c;
            } else {
                ss >> b;

                int mid = LCA(a, b);

                int mask = seg.Query(0, 0, in[a], 0, 2 * n - 1) ^
                            seg.Query(0, 0, in[b], 0, 2 * n - 1) ^
                            (1 << (s[mid] - 'a'));

                if ((mask & (mask - 1)) == 0) {
                    ans.push_back(true);
                } else {
                    ans.push_back(false);
                }
            }
        }

        return ans;
    }
};
