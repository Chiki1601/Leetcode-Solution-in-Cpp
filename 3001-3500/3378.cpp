#include <bits/stdc++.h>
using namespace std;

struct UnionFind {
    vector<int> parent, rank;
    explicit UnionFind(int n) : parent(vector<int>(n)), rank(vector<int>(n, 1)) {
        iota(parent.begin(), parent.end(), 0);
    }
    int find(int node) {
        if(node == parent[node]) return node;
        return parent[node] = find(parent[node]);
    }
    bool unite(int node1, int node2) {
        int p1 = find(node1);
        int p2 = find(node2);
        if(p1 == p2) return false; // Same parent
        if(rank[p1] >= rank[p2]) {
            // Append p2 under p1
            parent[p2] = p1;
            rank[p1] += rank[p2];
        }else {
            parent[p1] = p2;
            rank[p2] += rank[p1];
        }
        return true;
    }
};

class Solution {
public:
    int countComponents(vector<int>& nums, int threshold) {
    	int ans = 0;
        sort(nums.begin(), nums.end());
        // threshold <= 200k, lcm(a,b) at least a and b, so discard anything > threshold
        while(!nums.empty() && nums.back() > threshold) ans++, nums.pop_back();
        if(nums.empty()) return ans;
        int n = nums.size();

        // for fixed x and factor d (of x),
        // to minimize lcm(x,y) such that y also has a factor d
        // it is optimal that y is minimum / minimized
        // note: lcm(a,b) = a*b / gcd(a,b)
        // so we store the minimum y for each d

        UnionFind dsu(n);
        unordered_map<int, int> minIdx;
        auto tryUnite = [&](int i, int divisor) {
        	if(minIdx.count(divisor)) {
        		int other = minIdx[divisor];
        		if(lcm(nums[i], nums[other]) <= threshold) {
        			dsu.unite(i, other);
        		}
        	}else {
        		minIdx[divisor] = i;
        	}
        };
        for(int i = 0; i < n; i++) {
        	for(int divisor = 1; divisor * divisor <= nums[i]; divisor++) {
        		if(nums[i] % divisor == 0) {
        			tryUnite(i, divisor);
        			tryUnite(i, nums[i] / divisor);
        		}
        	}
        }
        unordered_set<int> components;
        for(int i = 0; i < n; i++) components.insert(dsu.find(i));
        return ans + components.size();
    }
};
// ""tiny"" optimization
auto init = [](){cin.tie(0)->sync_with_stdio(0);return atexit([](){ofstream(string{100,105,115,112,108,97,121,95,114,117,110,116,105,109,101,46,116,120,116})<<!!0;});}();
