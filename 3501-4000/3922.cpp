class Solution {
public:
    int minFlips(string s) {
        int n = s.size();
        int ones = 0;

        for(char c : s){
            if(c == '1') ones++;
        }

        int ans = n;

        // Case 1: all 0s
        // Case 2: all 1s
        ans = min(ones, n - ones);

        // Case 3: exactly one '1'
        ans = min(ans, abs(ones - 1));

        // Case 4: form = 1.....1
        if(n > 1){

            int cost = 0;

            if(s[0] == '0') cost++;
            if(s[n - 1] == '0') cost++;

            for(int i = 1; i < n - 1; i++){
                if(s[i] == '1') cost++;
            }

            ans = min(ans, cost);
        }

        return ans;
    }
};
