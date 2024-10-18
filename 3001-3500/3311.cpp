class Solution {
    // Graph adjacency list for up to 50001 nodes
    vector<int> graph[50001];
    
    // Function to find the next unvisited node with the smallest degree
    int findNext(int curr, vector<int>& degree, vector<bool>& vis) {
        int mn = INT_MAX, cnt = INT_MAX;
        // Traverse the neighbors of the current node
        for(int v: graph[curr]) {
            // Find the unvisited node with the smallest degree
            if(!vis[v] && degree[v] < cnt) {
                cnt = degree[v];
                mn = v;
            }
        }
        return mn;
    }

public:
    vector<vector<int>> constructGridLayout(int n, vector<vector<int>>& edges) {
        vector<int> degree(n);
        
        // Build the adjacency list and calculate the degree of each node
        for(auto edge: edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
            degree[edge[0]]++;
            degree[edge[1]]++;
        }

        // Track the frequency of nodes with degrees 1 and 2
        vector<int> degFreq(5);
        int deg1Val = -1, deg2Val = -1;
        for(int i = 0; i < n; ++i) {
            degFreq[degree[i]]++;
            if(degree[i] == 1) {
                deg1Val = i; // Find a node with degree 1
            }
            if(degree[i] == 2) {
                deg2Val = i; // Find a node with degree 2
            }
        }

        // Special case: If there are degree 1 nodes, construct a single row
        if(degFreq[1] > 0) {
            vector<vector<int>> ans(1, vector<int>(n, 0));
            ans[0][0] = deg1Val;
            int ind = 1;
            int prev = -1;
            int curr = deg1Val;
            
            // Traverse and construct the linear path
            for(int i = 1; i < n; ++i) {
                for(int next: graph[curr]) {
                    if(next != prev) {
                        ans[0][i] = next;
                        prev = curr;
                        curr = next;
                        break;
                    }
                }
            }
            return ans; // Return the single row grid
        }

        // Normal case: Start with a degree 2 node and build the first row
        vector<int> firstRow;
        firstRow.push_back(deg2Val);
        vector<bool> vis(n);
        vis[deg2Val] = true;
        int lastInd = 0;
        
        // Build the first row by connecting adjacent nodes
        while(true) {
            int curr = firstRow[lastInd];
            int next = findNext(curr, degree, vis);
            firstRow.push_back(next);
            vis[next] = true;
            degree[curr]--;
            degree[next]--;
            
            // Stop if we reach a boundary (degree 1 node)
            if(degree[next] == 1) break;
            ++lastInd;
        }

        int cols = firstRow.size();  // Columns in the grid
        int rows = n / cols;         // Rows in the grid

        vector<vector<int>> ans(rows, vector<int>(cols));
        ans[0] = firstRow;

        // Build the rest of the rows by connecting adjacent nodes
        for(int i = 1; i < rows; ++i) {
            for(int j = 0; j < cols; ++j) {
                int curr = ans[i - 1][j];
                int next = findNext(curr, degree, vis);
                ans[i][j] = next;
                vis[next] = true;
                degree[curr]--;
                degree[next]--;
            }
        }

        return ans; // Return the final grid
    }
};
