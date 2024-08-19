class Solution {
public:
    vector<long long> countKConstraintSubstrings(string s, int k, vector<vector<int>>& queries) 
    {
        long long n = s.size(),l,r,one=0,zero=0,cur,i,len;
        vector <long long> ans,pre(n+1),a(n);
        l = 0;
        for(r=0;r<n;r++)
        {
            s[r] == '1' ? one++ : zero++;
            while(zero > k && one > k)
            {
                s[l] == '1' ? one-- : zero--;
                l++;
            }
            cur = r - l + 1;
            a[r] = cur;
        }
        for(i=0;i<n;i++)
        {
            pre[i+1] = pre[i] + a[i];
        }
        for(auto &q : queries)
        {
            l = q[0];
            r = q[1];
            cur = 0;
            len = 0;
            for(i=l;i<=r;i++)
            {
                len++;
                if(a[i] <= len)
                {
                    cur = cur + pre[r+1] - pre[i];
                    break;
                }
                else
                {
                    cur = cur + len;
                }
            }
            ans.push_back(cur);
        }
        return ans;
    }
};
