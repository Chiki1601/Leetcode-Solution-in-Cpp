#define ll long long int
#define N 100005

class Solution {
public:
     
    vector<long long> handleQuery(vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& queries) {
        int n = nums1.size();
        vector<ll> ans;
        
        bitset<N> bset(0);
        ll sum = 0;
        bitset<N> binit(0);
        binit.flip();
        
        for(int i=0;i<n;i++){
            sum += nums2[i];
            if(nums1[i]==1) 
                bset[i] = 1;
        }
        
        for(auto q : queries){
            if(q[0] == 1){
                int sz = q[2] - q[1] + 1;
                bitset<N> btemp(binit<<sz);
                btemp = ~btemp;
                btemp <<= q[1];
                bset ^= btemp;
            }else if(q[0] == 2){
                sum += q[1] * bset.count();
            }else{
                ans.push_back(sum);
            }
        }
        
        return ans;
    }
};
