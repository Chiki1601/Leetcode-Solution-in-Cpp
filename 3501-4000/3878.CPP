class Solution {
public:
    long long countGoodSubarrays(vector<int>& nums) {
        int n = nums.size();
        vector<int> nder(n, n), ndel(n, -1);

        stack<int> st;
        for(int i=0; i<n; i++){
            // nums[i] is not submask of nums[st.top()]
            while(!st.empty() && ((nums[st.top()] | nums[i]) > nums[st.top()]) ){
                nder[st.top()] = i;
                st.pop();
            }

            st.push(i);
        }

        while(!st.empty()) st.pop();
        for(int i=n-1; i>=0; i--){
            while(!st.empty() && ( ((nums[st.top()] | nums[i]) > nums[st.top()]) || (nums[i] == nums[st.top()] )) ) {
                ndel[st.top()] = i;
                st.pop();
            }

            st.push(i);
        }


        long long ans = 0;
        for(int i=0; i<n; i++){
            long long r = nder[i] -i;
            long long l = i-ndel[i];
            ans += l *r;
        }

        return ans;
    }
};
