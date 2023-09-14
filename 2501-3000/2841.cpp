class Solution {
public:
    long long maxSum(vector<int>& nums, int m, int k) {
        
       map<long long, long long> mp;
       long long sum=0;
       long long maxsum =0;
       int j=0;

       for( int i=0;i<k ; i++){
           sum += nums[i];
           mp[nums[i]]++;
       }
       if(mp.size()>=m)
       maxsum =sum;

       for(int i=k ;i<nums.size() ;i++){
           sum += nums[i];
           sum -= nums[j];
           mp[nums[i]]++;
           mp[nums[j]]--;
           if(mp[nums[j]]==0) mp.erase(nums[j]);
            if(mp.size()>=m)
           maxsum = max(maxsum, sum);
           j++;

       }

       return maxsum;
        
    }
};
