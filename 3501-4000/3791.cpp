class Solution {
public:
 long long m[20][200][2];
 string s;
 int o = 100;

 long long dp(int ind, int b, bool t, int total) {
     if (b < 0 || b >= 200) return 0;
     if (ind == total) return b == o ? 1 : 0;
     if (ind >= 25) return 0;
     if (m[ind][b][t] != -1) return m[ind][b][t];

     long long ans = 0;
     int lim = t ? (s[ind] - '0') : 9;

     for (int i = 0; i <= lim; i++) {
         bool nex = t && (i == lim);
         int nb = b + ((ind % 2 == 0) ? i : -i);
         ans += dp(ind + 1, nb, nex, total);
     }

     return m[ind][b][t] = ans;
 }

 long long len(long long n) {
     if (n < 10) return 0;

     string s_num = to_string(n);
     int nlen = s_num.size();
     long long total = 0;

     // Count balanced numbers for lengths smaller than n
     for (int i = 2; i < nlen; i++) {
         memset(m, -1, sizeof(m));
         s = string(i, '9');
         for (int d = 1; d <= 9; d++) {
             total += dp(1, o + d, false, i);
         }
     }

     // Count balanced numbers of same length
     s = s_num;
     int firstS = s[0] - '0';

     for (int i = 1; i <= firstS; i++) {
         bool t = (i == firstS);
         memset(m, -1, sizeof(m));
         total += dp(1, o + i, t, nlen);
     }

     return total;
 }

 long long countBalanced(long long low, long long high) {
     return len(high) - len(low - 1);
 }
};
