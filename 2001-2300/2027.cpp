class Solution {
    
public:
    int minimumMoves(string s) {
    
        int ans = 0, i = 0;
        while(i < s.size())
        {
    
            if(s[i] == 'O')
                i++;
            else
            {
    
                ans++;
                i += 3;
            }
        }
        return ans;
    }
};
