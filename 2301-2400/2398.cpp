class Solution {
public:
    
    bool check(vector<int>& charge, vector<int>&running, long long &budget, int mid){
        long long sum = 0;
        long long value = 0;
        map<int, int> mp;
        priority_queue<int, vector<int>> pq;
        
        for(int i = 0; i < mid; i++){
            sum += running[i];
            pq.push(charge[i]);
        }
        
        value = sum;
        value *= mid;
        value += pq.top();
        
        if(value <= budget)
            return true;
        
        for(int i = mid; i < (int)charge.size(); i++){
            sum -= running[i - mid];
            
            mp[charge[i - mid]] ++;
            
            while(mp.find(pq.top()) != mp.end()){
                mp[pq.top()]--;
                if(mp[pq.top()] == 0)
                    mp.erase(pq.top());
                pq.pop();
            }
            
            sum += running[i];
            pq.push(charge[i]);
            
            value = sum;
            value *= mid;
            value += pq.top();

            if(value <= budget)
                return true;
        }
        
        return false;
    }
    
    int maximumRobots(vector<int>& chargeTimes, vector<int>& runningCosts, long long budget) {
        int n = chargeTimes.size();
        int l = 1, r = n;
        int ans = 0;
        while(l <= r){
            int mid = (l + r) / 2;
            if(check(chargeTimes, runningCosts, budget, mid)){
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return ans;
    }
};
