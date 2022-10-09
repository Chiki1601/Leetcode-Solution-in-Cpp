class Solution {
public:
    string robotWithString(string s) {
        int n = s.size();
        unordered_map<char, int> ump;
        vector<int> pre(n, 0);
        for(int i=n-1; i>=0; i--)
        {
            int num = s[i]-'a';
            ump[num] = max(ump[num], i);
            for(int j=0; j<num; j++)
                pre[i] = max(pre[i], ump[j]);
        }
        stack<pair<int, int>> stk;
        string ans="";
        for(int i=0; i<n; i++)
        {
            if(pre[i]==i)
                ans+=s[i];
            else
                stk.push({pre[i], s[i]});
            
            while(!stk.empty() && stk.top().first<=i)
            {
                ans += stk.top().second;
                stk.pop();
            }
        }
        
        return ans;
        
    }
};
