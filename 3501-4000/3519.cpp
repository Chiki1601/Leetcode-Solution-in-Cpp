class Solution {
public:
    int MOD = 1e9 + 7;
    // step 2: define the dp state
    // dp[digit pos][tight][lastDigit][leading zeros]
    int dp[350][2][11][2];
    int b;
    // step 3: change the number to base b
    vector<int> to_base_b(string& num){
        vector<int> res;
        string temp = num;
        while(temp != "0"){
            int rem = 0;
            string quotient = "";
            for(char c : temp){
                int curr = rem * 10 + (c - '0');
                quotient += (curr / b) + '0';
                rem = curr % b;
            }
            res.push_back(rem);
            //remove the leading zero from the quotient
            int i = 0;
            while(i < quotient.size() && quotient[i] == '0') i++;
            temp = i == quotient.size() ? "0" : quotient.substr(i);
        }
        reverse(res.begin(), res.end());
        return res;
    }

    int solve(vector<int>& digit, int ind, int tight, int lastDigit, int started){
        if(ind == digit.size()) return 1;

        if(dp[ind][tight][lastDigit][started] != -1) return dp[ind][tight][lastDigit][started];

        int limit = (tight == 1) ? digit[ind] : b - 1;
        int ans = 0;
        for(int i = 0; i <= limit; i++){
            if(started && i < lastDigit) continue;
            int newStarted =  started | (i != 0);
            int newTight = (tight & (i == limit));
            ans = (ans + solve(digit, ind + 1, newTight, i, newStarted)) % MOD;
        }

        return dp[ind][tight][lastDigit][started] = ans;
    }

    int countNumbers(string l, string r, int b) {
        this->b = b;
        // step 1: we will do l - 1: as the digits can go till 100 so we will do by string
        int lsize = l.size();
        string lminus = l;
        int last = lsize - 1;
        while(l[last] == '0'){
            lminus[last] = '9';
            last--;
        }
        int num = lminus[last] - '0';
        lminus[last] = (num - 1) + '0';

        memset(dp, -1, sizeof(dp));
        vector<int> digit = to_base_b(r);
        // step 4: digit dp on r 
        int right = solve(digit, 0, 1, 0, 0);
        memset(dp, -1, sizeof(dp));
        digit = to_base_b(lminus);
        // step 5: digit dp on l - 1
        int left = solve(digit, 0, 1, 0, 0);
        return (right - left + MOD) % MOD;
    }
};
