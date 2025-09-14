class Solution {
public:
    int earliestTime(vector<vector<int>>& tasks) {
        if (tasks.size() == 1) {
            int sum = 0;
            for (int t : tasks[0]) sum += t;
            return sum;
        }

        int min_task = 0;
        for (int t : tasks[0]) min_task += t;

        for (int i = 1; i < tasks.size(); ++i) {
            int sum = 0;
            for (int t : tasks[i]) sum += t;
            min_task = min(min_task, sum);
        }

        return min_task;
    }
};
     
