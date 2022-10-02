
class Solution {
public:
    int commonFactors(int a, int b) {
        int ctr=1;
        if(a==1 && b==1){
            return 1;
        }
        if(a>=b){
        for(int i=2;i<=a/2;i++){
            if(a%i == 0 && b%i==0){
                ctr++;
            }
        }
        }
        else{
            for(int i=2;i<=b/2;i++){
                if(a%i == 0 && b%i==0){
                ctr++;
            } 
            }
        }
        if(a==b) return ctr+1;
        return ctr;
    }
};
