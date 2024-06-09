class Solution {
public:
    int findWinningPlayer(vector<int>& s, int k) {
        int n = s.size();
        deque<int> pq;
        // Initialize the queue with players 1 to n-1
        for (int i = 1; i < n; i++) {
            pq.push_back(i);
        }
        int ele = 0, w = 0; // ele is the current winner, w is the win count
        while (true) {
            int num = pq.front();
            pq.pop_front();
            if (s[num] < s[ele]) {
                w++; // Current winner wins again
                pq.push_back(num); // Loser goes to end of queue
            } else {
                w = 1; // New winner found
                pq.push_back(ele); // Previous winner goes to end of queue
                ele = num; // Update current winner
            }
            if (w == k || w >= n - 1) return ele; 
            // if same player wins n - 1 times then hes the winner
            // to avoid TLE ---> skills = [15,18] k = 386830937
        }
        return 1; // This line should never be reached
    }
};
