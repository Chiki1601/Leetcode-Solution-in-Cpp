class Solution {
public:
    long long countSubstrings(string s) {
        int n = s.size();
        long long ans = 0;
        // Precompute prefix remainders for mod 3, 7, and 9
        vector<int> P3(n), P7(n), P9(n);
        P3[0] = (s[0]-'0') % 3;
        P7[0] = (s[0]-'0') % 7;
        P9[0] = (s[0]-'0') % 9;
        for (int i = 1; i < n; i++) {
            int dig = s[i]-'0';
            P3[i] = (P3[i-1]*10 + dig) % 3;
            P7[i] = (P7[i-1]*10 + dig) % 7;
            P9[i] = (P9[i-1]*10 + dig) % 9;
        }
        // Frequency arrays for remainder counts
        vector<long long> freq3(3,0), freq9(9,0);
        vector<vector<long long>> freq7(6, vector<long long>(7,0));
        int inv7[6] = {1,5,4,6,2,3};  // Precomputed inverses for 10^m mod 7
        // Process each ending index j
        for (int j = 0; j < n; j++) {
            int d = s[j]-'0';
            if (d == 0) {
                // Skip digit 0 as last digit
            } else if (d == 1 || d == 2 || d == 5) {
                // For d = 1,2,5: all substrings ending at j are valid → add (j + 1)
                ans += (j + 1);
            } else if (d == 4) {
                // For d = 4: Check if the last two digits form a number divisible by 4
                if (j == 0) ans += 1;
                else {
                    int num = (s[j-1]-'0') * 10 + d;
                    ans += (num % 4 == 0 ? (j + 1) : 1);
                }
            } else if (d == 8) {
                // For d = 8: Check last two or three digits for divisibility by 8
                if (j == 0) ans += 1;
                else if (j == 1) {
                    int num = (s[0]-'0') * 10 + 8;
                    ans += (num % 8 == 0 ? 2LL : 1LL);
                } else {
                    int num3 = (s[j-2]-'0') * 100 + (s[j-1]-'0') * 10 + 8;
                    int num2 = (s[j-1]-'0') * 10 + 8;
                    ans += ((num3 % 8 == 0 ? (j - 1) : 0) + (num2 % 8 == 0 ? 1 : 0) + 1);
                }
            } else if (d == 3 || d == 6) {
                // For d = 3 or 6: use prefix mod3 remainder
                ans += (P3[j] == 0 ? 1LL : 0LL) + freq3[P3[j]];
            } else if (d == 7) {
                // For d = 7: use prefix mod7 and adjust with cycle (10^m mod7)
                ans += (P7[j] == 0 ? 1LL : 0LL);
                for (int m = 0; m < 6; m++) {
                    int idx = ((j % 6) - m + 6) % 6;
                    int req = (P7[j] * inv7[m]) % 7;
                    ans += freq7[idx][req];
                }
            } else if (d == 9) {
                // For d = 9: use prefix mod9 remainder
                ans += (P9[j] == 0 ? 1LL : 0LL) + freq9[P9[j]];
            }
            // Update frequency arrays for future indices
            freq3[P3[j]]++;
            freq7[j % 6][P7[j]]++;
            freq9[P9[j]]++;
        }
        return ans;
    }
};
