class Solution {
public:
  vector<long long> unmarkedSumArray(vector<int>& nums, vector<vector<int>>& queries) {
    long long sum = 0;
    vector<long long> ans;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> pq;
    for(auto i = 0; i < nums.size(); ++i){ 
        sum += nums[i]; pq.push({nums[i], i}); 
    }

    for(auto q: queries){
        sum -= nums[q[0]];
        nums[q[0]] = 0;
        while(pq.size() && q[1]){
            if(nums[pq.top().second]){ 
                sum -= nums[pq.top().second];  
                nums[pq.top().second] = 0; 
                q[1]--; 
            }
            pq.pop();
        }
        ans.push_back(sum);
    }
    return ans;
}     
    
};
