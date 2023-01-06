class Solution {
public:
    int minimumPartition(string s, int k) 
    {
        int n = s.size();
        long long currNum = 0;
        long long prevNum = -1;
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            currNum = (currNum * 10) + (s[i] - '0');
            //=======================================================
            if (currNum <= k) continue;
            else if (currNum > k)
            {
                if (prevNum > k) return -1;
                ans++;
                currNum = (s[i] - '0');
            }  
            prevNum = currNum;
            //========================================================
        }
        if (prevNum > k) return -1;
        return (ans + 1);
        
    }
};
