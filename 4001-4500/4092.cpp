class Solution {
public:
    int calculateScore(int a, int b) {
        int s1=0,s2=0;
        while(a){
            int dig = a&1;
            if(dig == 1) s1++;
            a=a>>1;
        }
        while(b){
            int dig = b&1;
            if(dig == 1) s2++;
            b=b>>1;
        }
        if(s1>=s2) return s1*s2;
        return s2/s1;
    }
};
