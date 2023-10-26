class Solution { 
public: 
    int minProcessingTime(vector<int>& processorTimes, vector<int>& taskTimes) { 
        sort(processorTimes.begin(), processorTimes.end()); 
        sort(taskTimes.begin(), taskTimes.end(), [](const int a, const int b) { return a > b; }); 
        int processorIndex = 0, answer = 0; 
        for (int processingTime : processorTimes) { 
            int currentMax = 0, taskCount = 0; 
            while (processorIndex < taskTimes.size() && taskCount < 4) { 
                currentMax = max(currentMax, processingTime + taskTimes[processorIndex]); 
                processorIndex++; 
                taskCount++; 
            } 
            answer = max(answer, currentMax); 
        } 
        return answer; 
    } 
};
