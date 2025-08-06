using ll=long long int;
class Solution {
public:
    long long maxSumTrionic(vector<int>& nums) {
        ll n=nums.size();
        ll ans=-1e17;
        vector<ll>pref(n,0);
        pref[0]=nums[0];
        for(int i=1;i<n;i++)pref[i]=pref[i-1]+nums[i];
        vector<ll>inc(n,1);
        vector<ll>dec(n,1);
        ll ct1=1,ct2=1;
        for(int i=n-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                ct1++;
                ct2=1;
            }
            else if(nums[i]>nums[i+1]){
                ct1=1;
                ct2++;
            }
            else{
                ct1=1;
                ct2=1;
            }
            inc[i]=ct1;
            dec[i]=ct2;
        }
        for(int l=0;l<n-3;l++){
            if(inc[l]>1){
                int p=l+inc[l]-1;
                if(dec[p]>1){
                    int q=p+dec[p]-1;
                    if(inc[q]>1){
                        int r1=q+1;
                        int r2=q+inc[q]-1;
                        ll sum1=(pref[r1]-pref[l]+nums[l]);
                        ll sum2=(pref[r2]-pref[l]+nums[l]);
                        ll val=max(sum1,sum2);
                        ans=max(ans,val);
                    }
                }
            }
        }
        return ans;
    }
};
