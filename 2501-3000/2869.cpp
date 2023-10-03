class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        
        int n = nums.size();  
        unordered_map<int, int> mp;
        
        for(int i=1; i<=k; i++){
            mp[i]=0; //initially setting freq of all elements from 1 to k - as 0
        }
        
        int cnt = 0; // count of no. of operations
        
        for(int i=n-1; i>=0; i--){
            mp[nums[i]]++;
            cnt++;
            
            int x = 0; //cnt of all elements b/w 1 to k that are incorporated till now
            for(int j=1; j<=k ; j++){
                if(mp[j] > 0 ) x++;
            }
            if(x==k) return cnt; // if count(x) is equal to k => we have all required elements, so we return!
        }
        
        return 0;
    }
};
