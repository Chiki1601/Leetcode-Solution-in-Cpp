class Solution {
public:
    int pivotInteger(int n) {
        int s = 0, k = 0;
        for(int i=1; i<=n; i++) s += i;
        
        for(int i=1; i<=n; i++) {
            k += i;
            if(k == s) return i;
            s -= i;
        }
        return -1;
    }
};
