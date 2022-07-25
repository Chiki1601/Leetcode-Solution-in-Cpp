class Solution {
public:
    int maxSubArraySum(vector<int> &A){
        
        int n=A.size();
        
        int max_so_far = INT_MIN, max_ending_here = 0;

        for (int i = 0; i < n; i++){
            
            max_ending_here = max_ending_here + A[i];
            if (max_so_far < max_ending_here)
                max_so_far = max_ending_here;

            if (max_ending_here < 0)
                max_ending_here = 0;
        }
        
        return max_so_far;
    }
    int maximumsSplicedArray(vector<int>& nums1, vector<int>& nums2) {
        
        int n=nums1.size();
        
        vector<int> first(n,0);
        vector<int> second(n,0);
        
        int sum1=0;
        int sum2=0;
        
        for(int i=0;i<n;i++){
            sum1+=nums1[i];
            sum2+=nums2[i];
            first[i]=nums1[i]-nums2[i];
            second[i]=nums2[i]-nums1[i];
        }
        
        int res1=maxSubArraySum(first)+sum2;
        int res2=maxSubArraySum(second)+sum1;
        
        return max(res1,res2);
    }
};
