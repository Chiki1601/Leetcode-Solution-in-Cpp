constexpr int N=5e5+1;
bitset<N> sieve=0;
vector<int> primes;
class Solution {
public:
    static void Sieve(){
        if (primes.size()) return; // compute only once
        sieve[0]=sieve[1]=1;
        int Nsqrt=sqrt(N-1);
        for(int p=2; p<=Nsqrt; p+=1+(p&1)){
            if (!sieve[p]){
                primes.push_back(p);
                for(int i=p*p; i<N; i+=p) sieve[i]=1;
            }
        }
        for(int i=Nsqrt+((Nsqrt&1)==0); i<N; i+=2){
            if (!sieve[i])
                primes.push_back(i);
        }
    //    cout<<primes.size()<<endl;

    }
    static int largestPrime(int n) {
        Sieve();
        int sum=0, sz=primes.size(), i=0;
        int primeSum=0;
        for (; sum<=n && i<sz; i++){
            sum+=primes[i];
            if (sum>n) break;
            if (!sieve[sum]) primeSum=sum;
        }
        return primeSum;
    }
};
