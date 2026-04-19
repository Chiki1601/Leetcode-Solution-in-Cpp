class Solution {
public:
    int countDigitOccurrences(vector<int>& nums, int digit) {
        vector<int>d(10,0);
        for(int num :nums){
            while(num){
                d[num%10]++;
                num/=10;
            }
        }
        return d[digit];
    }
};
