class Solution {
public:
    
    bool check(int x,int m,int n){
        if(x*8>m)return false;
        
        m-=x*8;
        
        if(m<(n-x))return false;
        if(n-x==1 && m == 4)return false;
        if(n-x == 0 && m)return false;
        return true;
    }
    
    int distMoney(int money, int n) {
        int l = -1,r = n+1;
        while(l+1<r){
            int m = (l+r)>>1;
            if(check(m,money,n))l = m;
            else r = m;
        }
        return l;
    }
};
