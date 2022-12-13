class Solution {
public:
    int maxJump(vector<int>& s) {
        if(s.size()==2) return s[1];
        int n = s.size();
        
        int res = 0;
        int slow = s[1];
        int fast = s[2];
        res = max(slow,fast);
        for(int i = 1;i<n;i++)
        {
            if(i+2 < n && i%2==1) slow = max(slow,abs(s[i+2] - s[i]));
            if(i+2 < n && i%2==0) fast = max(fast,abs(s[i+2] - s[i]));
            
        }
        if(n%2 == 1) slow = max(slow,abs(s[n-1]-s[n-2]));
        else fast = max(fast,abs(s[n-1]-s[n-2]));
        res = max(res,max(slow,fast));
        return res;
    }
};
