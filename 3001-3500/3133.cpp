#define ll long long

class Solution {
public:
    long long minEnd(int nn, int xx) {
                
        ll ans = 0, bit;
        --nn; // reducing by 1 to exclude x
        
        vector<int> a(64, 0);
        vector<int> b(64, 0);
        
        ll x = xx; // converting to long long to get the 64 bit format
        ll n = nn;
        
        for(int i=0; i<64; ++i) // building the binary representation of x and n-1
        {
            bit = (x>>i)&1;
            a[i] = bit;
            
            bit = (n>>i)&1;
            b[i] = bit;
        }
        
        int pa = 0, pb = 0;
        
        while(pa < 63) // combining the binary representaion
        { 
            while(a[pa] != 0 && pa<63)
                ++pa;
            
            a[pa] = b[pb];   
            ++pa; ++pb;    
        }
        
    
        for(int i=0; i<64; ++i) // building the combined number
            if(a[i] == 1)
                ans+=pow(2, i);
        
        return ans; 
    }
};

