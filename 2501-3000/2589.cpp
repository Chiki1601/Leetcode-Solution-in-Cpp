class Solution {
public:
    int findMinimumTime(vector<vector<int>>& tasks) {
        sort(tasks.begin(),tasks.end(),[](vector<int>& a,vector<int>& b){
            return (a[1]!=b[1])?a[1]<b[1]:a[0]<b[0];
        });
        unordered_map<int,bool> used;       // time_slice... used or not ... 
        
        int count=0;
        for(auto& task:tasks){
            int usedTime=0;
            for(int t=task[0];t<=task[1];t++)   if(used.count(t))   usedTime++;      // have used this time slice

            for(int t=task[1];usedTime<task[2];t--){
                if(!used.count(t)){         // this time slice is available
                    usedTime++;             // duration for which I run it
                    used[t]=1;              // use this timeslice
                    count++;                // time for which my computer is on 
                }
            }
        }
        return count;
    }
};
