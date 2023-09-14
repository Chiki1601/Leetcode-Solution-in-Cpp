class Solution {
public:
    int longestEqualSubarray(vector<int>& v, int k) {
        int n=v.size();
        int i=0,j=0;
        map<int,int>m;
        int ans=1;
        int mf=0;
        while(j<n)
        {
            m[v[j]]++;
            mf=max(mf,m[v[j]]);
            int rem=j-i+1-mf;
            while(i<n && rem>k)
            {
                m[v[i]]--;
                i++;
                mf=max(mf,m[v[j]]);
                rem=j-i+1-mf;
            }
            ans=max(ans,mf);
            j++;
        }
        return ans;
    }
};
