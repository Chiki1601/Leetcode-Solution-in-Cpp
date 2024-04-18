class Solution {
public:
    
	// pre-compute primes in range O(nlog(logn))
    vector<bool> sieveOfEratosthenes(int n) {
        vector<bool> primes(n+1,true);
        
        primes[0]=primes[1]=false;
        for(int i=2;i*i<=n;i++){
            if(primes[i]){
                for(int j=i*i;j<=n;j+=i) primes[j]=false;
            }
        }
        
        return primes;
    }
    
    int maximumPrimeDifference(vector<int>& nums) {
        int n=nums.size();
        
        vector<bool> primes = sieveOfEratosthenes(101);
        
        int ans=0;
        int firstPrime=-1, j=0;
        while(j<n){
            if(primes[nums[j]]){
                if(firstPrime != -1){
                    ans = j-firstPrime;
                }else{
                    firstPrime = j;
                }
            }
            
            j++;
        }
        
        return ans;
    }
};
