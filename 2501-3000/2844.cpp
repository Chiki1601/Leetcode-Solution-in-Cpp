class Solution {
public:
    int solve(string s,string k)
    {   
        int n=s.size();
        int i=n-1,j=1;
        vector<int>v;
        while(i>=0)
        {
            if(s[i]==k[j])
            {
                v.push_back(i);
                j--;
            }
            if(j==-1)
                break;
            i--;
        }
        if(v.size()<2)
            return 1e5;
        int a=v[0],b=v[1];
        return (n-1)-a+a-b-1;
    }
    int minimumOperations(string s) {
        int n=s.size();
        int a=n;
        for(auto i:s)
        {
            if(i=='0')
            {
                a=a-1;
                break;
            }
        }
        a=min(a,solve(s,"00"));
        a=min(a,solve(s,"25"));
        a=min(a,solve(s,"50"));
        a=min(a,solve(s,"75"));
        return a;
    }
};
