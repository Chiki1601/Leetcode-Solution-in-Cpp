class Solution {
public:
    bool consecutiveSetBits(int n) {
        int ct=0;
        int cs=0;
        while(n>0){
            int bit=n&1;
            if(bit==1)cs++;
            else cs=0;
            if(cs>=2)ct++;
            n=n>>1;
        }
        return ct==1;
    }
};
