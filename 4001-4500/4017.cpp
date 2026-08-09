class Solution {
public:
    vector<long long> countOfPeaks(vector<int>& nums, vector<vector<int>>& queries) {
        struct T {
            int f=-1,l=-1;
            long long s=0;
        };

        auto mg=[](T a,T b) {
            if(a.f<0) return b;
            if(b.f<0) return a;
            return T{a.f,b.l,a.s+b.s+1LL*b.f*(b.f-a.l)};
        };

        int n=nums.size(),z=1;
        while(z<n) z*=2;
        vector<T> st(2*z);

        for(int i=1;i<n-1;i++)
            if(nums[i]>nums[i-1]&&nums[i]>nums[i+1])
                st[z+i]={i,i,0};

        for(int i=z-1;i;i--) st[i]=mg(st[i*2],st[i*2+1]);

        auto upd=[&](int p) {
            int v=z+p;
            st[v]={};
            if(nums[p]>nums[p-1]&&nums[p]>nums[p+1]) st[v]={p,p,0};
            for(v/=2;v;v/=2) st[v]=mg(st[v*2],st[v*2+1]);
        };

        auto get=[&](int l,int r) {
            T a,b;
            for(l+=z,r+=z;l<=r;l/=2,r/=2) {
                if(l&1) a=mg(a,st[l++]);
                if(!(r&1)) b=mg(st[r--],b);
            }
            return mg(a,b);
        };

        vector<long long> ans;

        for(auto &q:queries) {
            if(q[0]==1) {
                int l=q[1],r=q[2];
                T x=get(l+1,r-1);
                ans.push_back(x.f<0?0:1LL*r*(x.l-l)-1LL*x.f*(x.f-l)-x.s);
            } else {
                int i=q[1];
                nums[i]=q[2];
                for(int j=max(1,i-1);j<=min(n-2,i+1);j++) upd(j);
            }
        }

        return ans;
    }
};
