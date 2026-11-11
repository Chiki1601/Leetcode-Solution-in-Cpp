class Solution {
public:
    long long minimumMaxValue(int n, int index, int value) {
        if(value == 1){
            return -1;
        }
        long long pf = value;
        for(int i = 2;i * i <= value; i++){
            if(value % i == 0){
                pf = i;
                break;
            }
        }
        if(index > 0){
            if(value % 2 == 0){
                if(index > value / 2 - 1){
                    return -1;
                }
            }else{
                if(index > ((long long)value - pf) / 2){
                    return -1;
                }
            }
        }
        if(((long long)n - 1 - index) == 0){
            return value;
        }
        if(value % 2 == 0){
            return (long long)value + 2LL * ((long long)n - 1 - index);
        }
        return (long long)value + pf + 2LL * ((long long)n - 1 - index - 1);
    }
};
