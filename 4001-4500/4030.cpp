class Solution {
public:
    bool isPalindromic(string s) {
        int n=s.length();

        for(int i=0;i<=n/2;i++){
            int left=s[i];
            int right=s[n-1-i];

            for(int bit=0;bit<8;bit++){
                int leftBit=(left>>bit)&1;
                int rightBit=(right>>(7-bit))&1;
                if(leftBit!=rightBit)return false;
            }
        }

        return true;
    }
};
