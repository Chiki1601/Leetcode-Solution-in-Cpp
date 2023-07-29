class Solution {
public:
    int maxIncreasingGroups(vector<int>& a) {
        sort(a.begin(),a.end());
        long long t=0,ans=0;
        for(auto i:a)
        {
            t+=i;
            if(t>=(ans+1)*(ans+2)/2) ans++;
        }
        return ans;
    }
};
