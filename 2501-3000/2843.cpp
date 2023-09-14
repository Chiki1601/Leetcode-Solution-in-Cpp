class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int c=0;
        for(int i=low; i<=high; i++){
            if((int)floor(log10(i) + 1)%2) continue;
            else{
        int sum = 0;
        int n=i;
        int x=floor(log10(i) + 1);
            int    y=x/2;
        while (n != 0 && y--) {
            sum = sum + n % 10;
            n = n / 10;
        }
         y=x/2;
                int sum1=0;
        while (n != 0 && y--) {
            sum1 = sum1 + n % 10;
            n = n / 10;
        }
                if(sum1==sum) c++;
            }
        }
        return c;
    }
};
