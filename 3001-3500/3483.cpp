class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int freq[10]{};
        for(int digit:digits) freq[digit]++;
        int zero=0;
        int even=0;
        int all=0;
        for(int i=0; i<10; i++){
            if (freq[i]>0){
                if (i==0) zero++;
                if (i%2==0) even++;
                all++;
            }
        }
        // For unique digits
        int count = even*(all-1)*(all-2);
        if (zero==1) count-=(even-1)*(all-2);

        // For 2 same digit and 1 different
        for(int i=0; i<10; i++){
            if (freq[i]>=2){
                if (i==0) count+=all-1;
                else if (i%2==1) count+=even;
                else{
                    count+=3*(even-1)-zero;
                    count+=2*(all-even);
                }           
            }
        }

        // For all 3 digits same 
        for(int i=2; i<10; i+=2){
            if (freq[i]>=3){
                count++;
            }
        }
        return count;
    }
};
