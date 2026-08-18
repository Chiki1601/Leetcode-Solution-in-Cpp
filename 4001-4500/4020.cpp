class Solution {
public:
    int elevatorRequests(int n, vector<int>& requests) {
        int m = requests.size();
        int sum = 0;

        for (int i = 1; i < m; i++) {
            sum += abs(requests[i - 1] - requests[i]);
        }

        return sum + requests[0];
    }
};
