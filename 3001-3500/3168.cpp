class Solution {
public:
    int minimumChairs(string s) {
        int chairs = 0;
        int ans = 0;
        for(char ch : s){
            chairs += (ch == 'E' ? 1:-1);
            ans = max(ans, chairs);
        }
        return ans;
    }
};
