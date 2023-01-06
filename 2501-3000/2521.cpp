class Solution {
public:
    void prime(int n, set<int> &st)
    {
        while (n%2 == 0) 
        { 
            st.insert(2);
            n = n/2; 
        } 
        for (int i = 3; i <= sqrt(n); i = i+2) 
        { 
            while (n%i == 0) 
            { 
                st.insert(i);
                n = n/i; 
            } 
        }
        if (n > 2)
            st.insert(n);
    }
    
    int distinctPrimeFactors(vector<int>& nums) 
    {
        set<int> st;
        for (int i = 0; i < nums.size(); i++)
            prime(nums[i], st);
        return st.size();
    }
};
