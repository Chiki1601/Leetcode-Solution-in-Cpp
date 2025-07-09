typedef long long int ll;

class Solution {
public:
    vector<ll>seg;
    void build(int idx, int lo, int hi, vector<int> &a)
{
    if (lo == hi)
    {
        seg[idx] = a[lo];
        return;
    }
    int mid = lo + (hi - lo) / 2;
    build(2 * idx + 1, lo, mid, a);
    build(2 * idx + 2, mid + 1, hi, a);
    seg[idx] = __gcd(seg[2 * idx + 1], seg[2 * idx + 2]);
}
int query(int idx, int lo, int hi, int l, int r)
{
    if (r < lo || l > hi)
        return 0;
    if (lo >= l && hi <= r)
        return seg[idx];
    int mid = lo + (hi - lo) / 2;
    int left = query(2 * idx + 1, lo, mid, l, r);
    int right = query(2 * idx + 2, mid + 1, hi, l, r);
    return __gcd(left, right);
    }

    
    bool pos(ll mid,ll n,ll mx)
    {
        ll i;
        vector<ll>pos(n);
        for(i=0;i+mid-1<n;i++)
            {
                ll gc=query(0,0,n-1,i,i+mid-1);
                if(gc>=2)
                {
                    pos[i]=1;
                }
            }
        ll ct=0,prev=-1;
            for(i=0;i+mid-1<n;i++)
            {
                if(pos[i]&&i>prev)
                {
                    ct++;
                    if(ct>mx)
                        return false;
                    prev=i+mid-1;
                }
            }
        return true;
    }
    int minStable(vector<int>& nums, int maxC) {
        ll n=nums.size();
       seg.resize(4*n+1);
        build(0,0,n-1,nums);
        ll lo=1,hi=n;
        while(lo<=hi)
            {
                ll mid=lo+(hi-lo)/2;
                if(pos(mid,n,maxC))
                {
                    hi=mid-1;
                }
                else
                {
                    lo=mid+1;
                }
            }
        return hi;
    }
};
