class Solution {
public:
    vector<int> occurrencesOfElement(vector<int>& nums, vector<int>& queries, int x) {
        unordered_map<int, int> mp;  // Map to store occurrence count and corresponding index
        int count = 0;  // Counter for occurrences of x
        int n = nums.size();  // Size of the nums array

        // Traverse the nums array to count occurrences of x
        for(int i = 0; i < n; i++) {
            if(nums[i] == x) {
                count++;  // Increment count when x is found
                mp[count] = i;  // Map the current count to the index i
            }
        }

        // Process each query to find the index of the queries[i]th occurrence of x
        for(int i = 0; i < queries.size(); i++) {
            if(mp.find(queries[i]) != mp.end()) {
                // If the occurrence exists in the map, update queries[i] with the index
                queries[i] = mp[queries[i]];
            } else {
                // If the occurrence does not exist, update queries[i] with -1
                queries[i] = -1;
            }
        }

        // Return the modified queries array containing the results
        return queries;
    }
};
