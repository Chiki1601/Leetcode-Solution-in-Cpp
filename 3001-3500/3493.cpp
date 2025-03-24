class Solution {
public:
    // Arrays to store parent references and rank for union-find (disjoint set)
    vector<int> v1, v2;

    // Function to find the representative (root) of a set using path compression
    int find(int i) 
    {
        if (v1[i] != i)  // If i is not its own parent
        {
            v1[i] = find(v1[i]);  // Recursively find the root and apply path compression
        }
        return v1[i];  // Return the root of i
    }

    // Function to unite (merge) two sets using union by rank
    void unite(int i, int k) 
    {
        int a = find(i);  // Find root of i
        int b = find(k);  // Find root of k

        if (a != b)  // If they belong to different sets, merge them
        {
            if (v2[a] > v2[b]) 
            {
                v1[b] = a;  // Attach the smaller tree (b) to the larger tree (a)
            } 
            else if (v2[a] < v2[b]) 
            {
                v1[a] = b;  // Attach the smaller tree (a) to the larger tree (b)
            } 
            else 
            {
                v1[b] = a;  // Merge b into a and increase rank of a
                v2[a]++;    
            }
        }
    }

    // Function to count the number of connected components
    int numberOfComponents(vector<vector<int>>& p, int k) 
    {
        int n = p.size();  // Number of elements (nodes)

        // Initialize disjoint set
        v1.resize(n);  // Parent array
        v2.resize(n, 0);  // Rank array (initially all 0)

        for (int i = 0; i < n; i++) 
        {
            v1[i] = i;  // Each node is its own parent initially
        }

        // Create an adjacency map to store element frequency for each node
        vector<unordered_map<int, int>> mp(n);
        for (int i = 0; i < n; i++) 
        {
            for (int j : p[i]) 
            {
                mp[i][j] = mp[i][j] + 1;  // Count occurrences of each element in node i
            }
        }

        // Compare each pair of nodes to check common elements
        for (int i = 0; i < n; i++) 
        {
            for (int j = i + 1; j < n; j++) 
            {
                int cmn = 0;  // Count of common elements between node i and node j
                
                // Check for common elements between node i and j
                for (auto it = mp[i].begin(); it != mp[i].end(); it++) 
                {
                    int num = it->first;  
                    if (mp[j].find(num) != mp[j].end())  // If element exists in both nodes
                    {
                        cmn++;
                    }
                }

                // If the count of common elements is greater than or equal to k, merge them
                if (cmn >= k) {
                    unite(i, j);
                }
            }
        }

        // Count the number of unique connected components
        unordered_set<int> st;
        for (int i = 0; i < n; i++) 
        {
            st.insert(find(i));  // Insert unique root representatives into the set
        }

        return st.size();  // The number of unique roots gives the number of components
    }
};
