class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {
        //kth character look at binary represenation
        //go through bits of k-1 backwards
        int inc = 0;
        k--;

        //Find Position of Highest Order Bit
        long long l = k;
        int bits = 0;
        while(l>>=1){
            bits++;
        }

        //apply operations
        for(int i = bits; i >=0; i--){
            int bit = (k >> i) & 1;
            if(bit) inc += operations[i];
        }
        return (inc%26) + 'a';
    }
};
