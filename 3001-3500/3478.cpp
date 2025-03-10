class Solution {
public:
    vector<long long> findMaxSum(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        vector<long long> ans(n, 0); // Result array initialized with 0
        
        // Store {nums1[i], index} and sort by nums1[i] to process in increasing order
        vector<pair<int, int>> idx;
        for (int i = 0; i < n; i++) 
            idx.push_back({nums1[i], i});
        
        sort(idx.begin(), idx.end());
        
        priority_queue<int, vector<int>, greater<int>> pq; // Min-Heap to track largest `k` elements from nums2
        unordered_map<int, long long> mp; // Stores sum for each index
        long long sum = 0;
        int j = 0; // Pointer to track valid elements in heap
        
        for (int i = 0; i < n; i++) {
            int index = idx[i].second; // Original index of nums1[i]
            
            // Add valid elements from nums2 to min-heap
            while (j < i) {
                int prev = idx[j].second; // Original index of the previous element
                
                // Stop if the current element in nums1 is not strictly greater
                if (idx[j].first >= idx[i].first) break;

                pq.push(nums2[prev]);
                sum += nums2[prev];

                // If heap exceeds size k, remove the smallest element
                if (pq.size() > k) {
                    sum -= pq.top();
                    pq.pop();
                }
                j++;
            }
            
            mp[index] = sum; // Store the sum for the current index
        }
        
        // Assign computed sums to the result array
        for (int i = 0; i < n; i++)
            ans[i] = mp[i];

        return ans;
    }
};
