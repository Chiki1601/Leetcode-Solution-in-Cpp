class Solution {
public:
    typedef long long ll;
    long long numOfSubsequences(string s) {
        int n=s.size();
        vector<ll> prefix(n+1, 0); // lcount 1 based
        vector<ll> suffix(n+1, 0); // tcount 0 based
        for(int i=0; i<n; i++){
            if(s[i]=='L'){
                prefix[i+1]=1;
            }
            prefix[i+1]+=prefix[i];
        }
        for(int i=n-1; i>=0; i--){
            if(s[i]=='T'){
                suffix[i]=1;
            }
            suffix[i]+=suffix[i+1];
        }
        ll resWithC=0;
        ll bestPosForC=0;
        ll resWithL=0;
        ll resWithT=0;
        for(int i=0; i<n; i++){
            // if we place l or t to the left ot right
            if(s[i]=='C'){
                resWithC+=prefix[i]*suffix[i+1];
                resWithL+=(prefix[i]+1)*suffix[i+1];
                resWithT+=prefix[i]*(suffix[i+1]+1);
            }
            else{
                // if we place C
                bestPosForC = max(prefix[i]*suffix[i], bestPosForC);
            }
            
        }
        resWithC+=bestPosForC;
        return max({resWithL, resWithT, resWithC});
        
    }
};
