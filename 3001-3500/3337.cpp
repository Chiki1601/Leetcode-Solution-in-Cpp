class Solution {
    public int MOD = 1000000007;
    public int lengthAfterTransformations(String s, int t, List<Integer> nums) {
        if (t == 0) {
            return s.length() % MOD;
        }
        
        long[] freq = new long[26];
        for (char c : s.toCharArray()) {
            freq[c - 'a']++;
        }
        
        long[][] M = new long[26][26];
        for (int c = 0; c < 26; c++) {
            int num = nums.get(c);
            for (int i = 1; i <= num; i++) {
                M[c][(c + i) % 26] = 1;
            }
        }
        
        long[][] Mt = matrixPow(M, t);
        
        long[] rowSums = new long[26];
        for (int c = 0; c < 26; c++) {
            for (int j = 0; j < 26; j++) {
                rowSums[c] = (rowSums[c] + Mt[c][j]) % MOD;
            }
        }
        
        long total = 0;
        for (int c = 0; c < 26; c++) {
            total = (total + (freq[c] * rowSums[c]) % MOD) % MOD;
        }
        
        return (int) total;
    }
    
    private long[][] matrixPow(long[][] M, int power) {
        long[][] res = new long[26][26];
        for (int i = 0; i < 26; i++) {
            res[i][i] = 1;
        }
        long[][] base = new long[26][26];
        for (int i = 0; i < 26; i++) {
            System.arraycopy(M[i], 0, base[i], 0, 26);
        }


        while (power > 0) {
            if ((power & 1) == 1) {
                res = multiply(res, base);
            }
            base = multiply(base, base);
            power >>= 1;
        }
        return res;
    }
    
    private long[][] multiply(long[][] A, long[][] B) {
        long[][] C = new long[26][26];
        
        for (int i = 0; i < 26; i++) {
            for (int k = 0; k < 26; k++) {
                if (A[i][k] == 0) continue;
                for (int j = 0; j < 26; j++) {
                    C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD;
                }
            }
        }
        return C;
    }
}
