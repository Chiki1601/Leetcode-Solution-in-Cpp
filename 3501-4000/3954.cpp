class Solution {
public:
    int sumOfGoodIntegers(int n, int k) {
        int ans=0;
        for(int i=max(1,n-k);i<=n+k;i++){
            if((n&i)==0)ans+=i;
        }
        return ans;
    }
};
