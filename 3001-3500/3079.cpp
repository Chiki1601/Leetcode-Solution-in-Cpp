class Solution {
public:
    int sumOfEncryptedInt(vector<int>& nums) {
        int ans = 0, x = 0, k = 0, y = 0;
        for(auto i: nums){
            x = 0, k = 0;
            while(i){
                x = max(x,(i%10));
                k++;
                i /= 10;
            }
            y = 0;
            while(k--){
                y = (y*10)+x;
                
            }
            ans += (y);
        }
        return ans;
    }
};
