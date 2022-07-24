class Solution {
public:
    int maxEvents(vector<vector<int>>& A) {
        sort(A.begin(), A.end());
        priority_queue<int, vector<int>, greater<int>> pq;
        int N = A.size(), i = 0, day = A[0][0], ans = 0;
        while (i < N || pq.size()) {
            if (pq.empty()) day = A[i][0]; // If no active event is available and there are still more events to pick, jump to the start date of the next event.
            while (i < N && A[i][0] == day) pq.push(A[i++][1]); // add events that start at `day` as active events, push their end time into queue
            pq.pop(); // pick the event with the earliest start time
            ++ans;
            ++day;
            while (pq.size() && pq.top() < day) pq.pop(); // ignore the events that are no longer active
        }
        return ans;
    }
};
