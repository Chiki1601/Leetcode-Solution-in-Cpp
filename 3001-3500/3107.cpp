class Solution {
public:
    long long solve(vector<int>&v,int k,int idx) {
        int n=v.size();
        long long ans=0;
        int m=v[idx];
            if(m<k) {
                ans=ans+k-m;
                for(int i=idx+1;i<n;i++) {
                    if(v[i]<=k) {
                        ans=ans+k-v[i];
                    }
                    else
                        break;
                }
            }
            else if(m>k) {
                ans=ans+m-k;
                for(int i=idx-1;i>=0;i--) {
                    if(v[i]>=k) {
                        ans=ans+v[i]-k;
                    }
                    else
                        break;
                }
            }
        return ans;
    }
    long long minOperationsToMakeMedianK(vector<int>& v, int k) {
        int n=v.size();
        long long ans=0;
        sort(v.begin(),v.end());
        if(n%2!=0) {
            ans=solve(v,k,n/2);
                
        } else {
            ans=solve(v,k,n/2);
            
        }
        return ans;
    }
};
