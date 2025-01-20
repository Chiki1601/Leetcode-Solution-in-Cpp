class Solution {
public:
    long long minMaxSubarraySum(vector<int>& nums, int k) {
        long long res = 0, total = 0; // total => all contribution associted to a window
        deque<pair<int,int>> dq; // {nums[r], r - i}
        int n = nums.size(), l = 0;

        // count max value 
        for(int r = 0; r < n; ++r){
            if(r - l + 1 > k){
                total -= nums[dq.front().first];
                --dq.front().second;
                ++l;
            }
            while(!dq.empty() && dq.front().first < l){
                total -= 1L * dq.front().second * nums[dq.front().first];
                dq.pop_front();
            }
            while(!dq.empty() && nums[dq.back().first] < nums[r]){
                total -= 1L * dq.back().second * nums[dq.back().first];
                dq.pop_back();
            }
            
            long long cnt = dq.empty()? min(r - l + 1, k): r - dq.back().first;
            total += cnt * nums[r];
            res += total;
            
            dq.push_back({r, cnt});
        }


        // count min value
        l = 0;
        dq.clear();
        total = 0;
        
        for(int r = 0; r < n; ++r){
            if(r - l + 1 > k){
                total -= nums[dq.front().first];
                --dq.front().second;
                ++l;
            }
            while(!dq.empty() && dq.front().first < l){
                total -= 1L * dq.front().second * nums[dq.front().first];
                dq.pop_front();
            }
            while(!dq.empty() && nums[dq.back().first] > nums[r]){
                total -= 1L * dq.back().second * nums[dq.back().first];
                dq.pop_back();
            }
            
            long long cnt = dq.empty()? min(r - l + 1, k): r - dq.back().first;
            total += cnt * nums[r];
            res += total;
            
            dq.push_back({r, cnt});
        }
        
        return res;
    }
};
