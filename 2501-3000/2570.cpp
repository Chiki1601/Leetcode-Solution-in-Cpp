class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        for(int i=0;i<nums1.size();i++){
            int x = nums1[i][0];
            for(int j=0;j<nums2.size();j++){
                if(nums2[j][0]==x){
                    nums1[i][1] += nums2[j][1];
                    nums2[j] = {-1,-1};
                }
            }
        }
        for(int i=0;i<nums2.size();i++){
            if(nums2[i][0] !=-1 && nums2[i][1] !=-1){
                nums1.push_back(nums2[i]);
            }
        }
        sort(nums1.begin(),nums1.end(),[](vector<int> a,vector<int> b){
           return a[0]<b[0]; 
        });
        return nums1;
    }
};
