#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int maximumLength(string s)
    {
        int ans = 0;
        int n = s.length();
        for (char cc = 'a'; cc <= 'z'; cc++)
        {
            int ct= 0;
            vector<int> counts; // stores consecutive counts of a character..
            for (int i = 0; i < n; i++)
            {
                if (s[i] == cc)
                    ct++;
                else
                {
                    if (ct!= 0)counts.push_back(ct);
                    ct= 0;
                }
            }
            if (ct!= 0)counts.push_back(ct);
            sort(counts.begin(),counts.end());
            reverse(counts.begin(),counts.end());
            int cnt_size = counts.size();
            if (cnt_size == 0) continue; // no occurence of this character..
            else if (cnt_size == 1)
            {
               ans = max(ans,counts[0] - 2); 
            }
            else if (cnt_size == 2)
            {
                ans = max(ans,counts[0]  - 2); // same as above.. 
                if (counts[0] == counts[1])
                {
                    ans = max(ans,counts[0] - 1); 
                    /*
                    5 5 comes 
                    we take 4 from first and 4 2 times from second.. 
                    */
                }
                else 
                {
                    /*
                    4 5 comes let's say we take 4 from first and 4 2 times from second
                    */
                    ans = max(ans,counts[1]);
                }
            }
            else 
            {
                ans = max(ans,counts[0] - 2); // first one only {6,3,3}
                if (counts[0] == counts[1]) ans = max(ans,counts[0] - 1); // first and second
                else ans = max(ans,counts[1]); // first and second 
                ans = max(ans,counts[2]); // we take help from third one  {5,5,5}
            }
        }
        if (ans == 0) ans = -1;
        return ans;
    }
};
