class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size(); 
        vector<int>freq(n+1,0);         
        for(auto i:queries){
            freq[i[0]]++;
            freq[i[1]+1]--;
        }
        int op=0;
        for(int i=0;i<n;i++){
            op+=freq[i];
            if(op<nums[i])return false;
        }
        return true;        
    }
};
