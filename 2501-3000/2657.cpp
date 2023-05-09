class Solution {
public:
  vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        unordered_map<int, int> m1, m2;
        for(int i = 0; i < n; i++) {
            m1[A[i]] = i;
            m2[B[i]] = i;
        }
        vector<int> c(n);
        for(int i = 0; i < n; i++) {
            int cnt = 0;
            for(int j = 0; j <= i; j++) {
                if(m1[A[j]] <= i && m2[A[j]] <= i) {
                    cnt++;
                }
            }
            c[i] = cnt;
        }
        return c;
    }
};
