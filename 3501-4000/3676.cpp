class Solution {
public:
    long long bowlSubarrays(vector<int>& nums) {
        int n=nums.size();
        vector<int> left(n,-1);
        stack<int> st;
        int i=0;
        for(auto it:nums){
            while(!st.empty() && nums[st.top()]<it){
                st.pop();
            }
            if(!st.empty()){
                left[i]=st.top();
            }
            st.push(i);
            i++;
        }
        while(!st.empty()){
            st.pop();
        }
        vector<int> right(n,n);
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && nums[st.top()]<nums[i]){
                st.pop();
            }
            if(!st.empty()){
                right[i]=st.top();
            }
            st.push(i);
        }
        long long ans=0;
        for(int i=0;i<n;i++){
            if(left[i]!=-1 && right[i]!=n){
                ans++;
            }
        }
        return ans;
    }
};
