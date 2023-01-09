class Solution {
public:
    bool check(long long  mid , vector<long long>  ans, int r , int k){
        long long sum=0;
        int n=ans.size();
        for(int i=0;i<r;i++)
            sum+=ans[i];
        for(int i=0;i<n;i++){
            sum+=((i+r<=n-1)?ans[i+r]:0)-((i-r-1>=0)?ans[i-r-1]:0);
            if(sum<mid){
                    if(mid-sum>k)
                        return false;
                if(i+r<=n-1)ans[i+r]+=mid-sum;
                k-=mid-sum;
                sum=mid;
            }
        }
        return true;
    }
    long long maxPower(vector<int>& stations, int r, int k) {
        long long  l=0;
        long long h=k;
        int n=stations.size();
        for(int i=0;i<n;i++)
            h+=1LL*stations[i];
        vector<long long> ans(n);
        for(int i=0;i<n;i++)
            ans[i]=stations[i];
        while(l<h){
            long long  mid=h+(l-h)/2;
            if(check(mid,ans,r,k))
                l=mid;
            else
                h=mid-1;
        }
        return l;
    }
};
