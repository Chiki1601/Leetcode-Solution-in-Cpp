class Solution {
public:
    int maxSumDistinctTriplet(vector<int>& x, vector<int>& y) {
        int n = x.size();
        unordered_map<int, int> yx;

        for(int i = 0; i < n; ++i) {
            yx[x[i]] = max(yx[x[i]], y[i]);
        }

        priority_queue<int> maxHeap;
        for(auto& [key, val] : yx) {
            maxHeap.push(val);
        }

        if(maxHeap.size() < 3) return -1;

        int sum = 0;
        for(int i = 0; i < 3; ++i) {
            sum += maxHeap.top();
            maxHeap.pop();
        }
        return sum;
    }
};
