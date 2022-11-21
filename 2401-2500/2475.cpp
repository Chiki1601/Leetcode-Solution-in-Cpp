class Solution 
{
public:
    int unequalTriplets(vector<int>& nums)
    {
        int cnt = 0, prv = 0, nxt = nums.size();
        unordered_map<int,int> freq;
        for (int n : nums) freq[n]++;
        
        for (auto[n,cur] : freq)
        {
            nxt -= cur;
            cnt += prv * cur * nxt;
            prv += cur;

        }

        return cnt;
    }
};
