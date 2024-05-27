class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& q) {
        // q[i][0] -> ball, q[i][1] -> color
        unordered_map<int, int> mp; // Tracks the current color of each ball
        unordered_map<int, int> st; // Tracks the count of each color
        vector<int> v(q.size()); // Result vector to store the number of distinct colors after each query
        
        for(int i = 0; i < q.size(); i++){
            int ball = q[i][0]; // Get ball number
            int col = q[i][1]; // Get color
            if(mp.find(ball) != mp.end()){ // Ball is already colored
                int exisCol = mp[ball]; // Get existing color
                if(st[exisCol] == 1) st.erase(exisCol); // Remove color if its count is 1
                else st[exisCol]--; // Decrement the count of the existing color
                mp[ball] = col; // Update the ball's color
                st[col]++; // Increment the count of the new color
            }
            else{ // Ball is not colored
                mp[ball] = col; // Set the ball's color
                st[col]++; // Increment the count of the new color
            }
            v[i] = st.size(); // Store the number of distinct colors
        }
        
        return v; // Return the result vector
    }
};
