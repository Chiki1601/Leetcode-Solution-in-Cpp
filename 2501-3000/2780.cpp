class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        unordered_map<int,int> m1,m2;
        int n=nums.size();
        
        for(int i=0;i<n;i++)
            m2[nums[i]]++;
        
        for(int i=0;i<n;i++) {
            int x = ++m1[nums[i]];
            int y = --m2[nums[i]];
            
            if(x*2>(i+1) && y*2>(n-i-1)) //i+1 (total element in left), n-i-1 (total elements in right)
            return i;
        }
        
        return -1;
    }
};
