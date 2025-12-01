class Solution {
public:

    struct RemTree {
        int n;
        vector<int> lo, hi;
        RemTree(const vector<int>& a){
            n=a.size();
            lo.resize(4*n);
            hi.resize(4*n);
            build(1,0,n-1,a);
        }
        void build(int idx,int l,int r,const vector<int>&a){
            if(l==r){lo[idx]=hi[idx]=a[l];return;}
            int m=(l+r)/2;
            build(idx*2,l,m,a);
            build(idx*2+1,m+1,r,a);
            lo[idx]=min(lo[idx*2],lo[idx*2+1]);
            hi[idx]=max(hi[idx*2],hi[idx*2+1]);
        }
        pair<int,int> getVal(int idx,int l,int r,int L,int R){
            if(R<l||r<L)return {INT_MAX,INT_MIN};
            if(L<=l&&r<=R)return {lo[idx],hi[idx]};
            int m=(l+r)/2;
            auto a=getVal(idx*2,l,m,L,R);
            auto b=getVal(idx*2+1,m+1,r,L,R);
            return {min(a.first,b.first),max(a.second,b.second)};
        }
    };

    struct MST {
        int n;
        vector<vector<long long>> v,p;
        MST(const vector<long long>&a){
            n=a.size();
            v.resize(4*n);
            p.resize(4*n);
            build(1,0,n-1,a);
        }
        void build(int idx,int l,int r,const vector<long long>&a){
            if(l==r){
                v[idx]={a[l]};
                p[idx]={a[l]};
                return;
            }
            int m=(l+r)/2;
            build(idx*2,l,m,a);
            build(idx*2+1,m+1,r,a);
            auto &L=v[idx*2], &R=v[idx*2+1];
            v[idx].resize(L.size()+R.size());
            merge(L.begin(),L.end(),R.begin(),R.end(),v[idx].begin());
            p[idx].resize(v[idx].size());
            long long s=0;
            for(int i=0;i<(int)v[idx].size();i++){
                s+=v[idx][i];
                p[idx][i]=s;
            }
        }
        pair<long long,long long> le(int idx,int l,int r,int L,int R,long long x){
            if(R<l||r<L)return {0,0};
            if(L<=l&&r<=R){
                auto &A=v[idx]; auto &P=p[idx];
                int pos=upper_bound(A.begin(),A.end(),x)-A.begin();
                long long s=pos?P[pos-1]:0;
                return {pos,s};
            }
            int m=(l+r)/2;
            auto a=le(idx*2,l,m,L,R,x);
            auto b=le(idx*2+1,m+1,r,L,R,x);
            return {a.first+b.first,a.second+b.second};
        }
        long long sum(int idx,int l,int r,int L,int R){
            if(R<l||r<L)return 0;
            if(L<=l&&r<=R)return p[idx].back();
            int m=(l+r)/2;
            return sum(idx*2,l,m,L,R)+sum(idx*2+1,m+1,r,L,R);
        }
    };

    vector<long long> minOperations(vector<int>& nums,int k,vector<vector<int>>& queries){
        int n=nums.size();
        vector<int> rem(n);
        vector<long long> sc(n);
        for(int i=0;i<n;i++){
            rem[i]=nums[i]%k;
            sc[i]=nums[i]/(long long)k;
        }

        RemTree rt(rem);
        MST mt(sc);

        vector<long long> uniq=sc;
        sort(uniq.begin(),uniq.end());
        uniq.erase(unique(uniq.begin(),uniq.end()),uniq.end());

        vector<long long> res;
        res.reserve(queries.size());

        for(auto &q:queries){
            int L=q[0],R=q[1];
            auto g=rt.getVal(1,0,n-1,L,R);
            if(g.first!=g.second){
                res.push_back(-1);
                continue;
            }

            int len=R-L+1,need=(len+1)/2;
            long long tot=mt.sum(1,0,n-1,L,R);

            int lo=0,hi=uniq.size()-1,best=hi;
            while(lo<=hi){
                int mid=(lo+hi)/2;
                auto t=mt.le(1,0,n-1,L,R,uniq[mid]);
                if(t.first>=need){
                    best=mid;
                    hi=mid-1;
                } else lo=mid+1;
            }

            long long med=uniq[best];
            auto le=mt.le(1,0,n-1,L,R,med);
            long long cL=le.first, sL=le.second;
            long long cR=len-cL, sR=tot-sL;

            res.push_back(med*cL - sL + sR - med*cR);
        }
        return res;
    }
};
