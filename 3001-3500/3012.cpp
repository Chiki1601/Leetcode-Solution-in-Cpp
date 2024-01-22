class Solution {
public:
    int minimumArrayLength(vector<int>& v) {
        sort(v.begin(),v.end());
        int n=v.size();
        int c=1;
        int g=INT_MAX;
        for(int i=1;i<n;i++) {
            g=min(g,__gcd(v[i],v[i-1]));
            if(g<v[0])
                return 1;
            if(v[i]==v[0])
                c++;
        }
        int k=ceil(c/(2*1.0));
        return k;
    }
};
