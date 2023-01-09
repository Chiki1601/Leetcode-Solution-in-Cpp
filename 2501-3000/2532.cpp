struct State {
    int time;
    // -1: not specified
    // 0: left to right
    // 1: pickOld
    // 2: right to left
    // 3: put New
    int donetask;
    // -1: not specified
    int worker;
    
};

class Solution {
public:
    int findCrossingTime(int n, int k, vector<vector<int>>& time) {
        // k * 4
        // time[i] = [leftToRighti, pickOldi, rightToLefti, putNewi].
        
        // left queue and right queue
        priority_queue<vector<int>> lq, rq;
        
        // put all worker into lq
        for (int i = 0; i < k; ++i) {
            // bridge time, index
            lq.push(gets(i, time));
        }
        
        // timestamp queue: State: [time, done task, worker]
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> tq;
        tq.push({0, -1, -1});
        
        // current time
        int t = 0;
        // last worker for get last putNew time
        int lw = -1;
        
        // whether bridge is in use
        bool bridge = false;
        
        while (tq.size()) {
            // cur time
            t = tq.top()[0];
            
            // process all same time
            while (tq.size() && tq.top()[0] == t) {
                auto ts = tq.top();
                int dt = ts[1]; // done task
                int worker = ts[2]; // worker index
                tq.pop();
                
                if (dt == 1) {
                    // done pick old, add to rq
                    rq.push(gets(worker, time));
                } else if (dt == 3) {
                    // done put new, add to lq
                    lq.push(gets(worker, time));
                } else if (dt == 0) {
                    // crossed bridge from left to right, next pick old
                    tq.push({t + time[worker][1], 1, worker});
                    n--;
                    bridge = false;
                } else if (dt == 2) {
                    // crossed bridge from right to left, next put new
                    tq.push({t + time[worker][3], 3, worker});
                    lw = worker;
                    bridge = false;
                }    
            }
            
            // if bridge in use, nothing can do
            if (bridge) continue;
            
            // bridge should be false/free here
            if (!rq.empty()) {
                // if someone waiting on right
                
                // get worker
                auto v = rq.top();
                rq.pop();
                
                int cw = v[1];
                
                // this worker will cross from right to left
                tq.push({t + time[cw][2], 2, cw});
                
                // put bridge in use
                bridge = true;
            } else if (n && !lq.empty()) {
                // if there's box on the right and no one waiting on the right
                
                // get worker
                auto v = lq.top();
                lq.pop();
                
                int cw = v[1];
                
                // this worker will cross left to right
                tq.push({t + time[cw][0], 0, cw});
                
                // put bridge in use
                bridge = true;
            } 
        }
        
        return t - time[lw][3];
    }
    
    vector<int> gets(int i, vector<vector<int>>& time) {
        vector<int> v = time[i];
        return {v[0] + v[2], i};
    }
};
