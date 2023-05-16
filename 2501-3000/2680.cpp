class Solution {
public:
    long long maximumOr(vector<int>& nums, int k) {
    int n = nums.size();
    vector<long long> pre(n + 1, 0); // Stores prefix bitwise OR values
    vector<long long> suf(n + 1, 0); // Stores suffix bitwise OR values
    pre[0] = 0;
    suf[n] = 0;
    long long res = 0;
    long long p = 1; // Used to calculate the power of 2, equivalent to x^k
    p = p << k; // Left shift k positions to calculate 2^k

    // Calculate prefix bitwise OR values
    for (int i = 0; i < n; i++) {
        pre[i + 1] = pre[i] | nums[i];
    }

    // Calculate suffix bitwise OR values
    for (int i = n - 1; i >= 0; i--) {
        suf[i] = suf[i + 1] | nums[i];
    }

    // Find the maximum result by iterating through the numbers
    for (int i = 0; i < n; i++) {
//	cout<<"res= "<<res<< " If current num is multiped by 2 k times then answer will be= "<<(pre[i] | (nums[i] * p) | suf[i + 1])<<endl; 
        res = max(res, pre[i] | (nums[i] * p) | suf[i + 1]);
    }

    return res;
}        
    
};
