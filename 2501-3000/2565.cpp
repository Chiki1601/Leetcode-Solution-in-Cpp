class Solution {
public:
    int minimumScore(string s, string t) {
        int n = s.size(), m = t.size(); 
        vector<int> l(m, -1), r(m, -1); //left, right arrays. 
        int j = 0; 
        for (int i = 0; i < n; ++i) {
            if (j >= m) break; 
            if (s[i] == t[j]) {
                l[j] = i; //for a prefix of t from 0...j, i is the greatest 
                //index in s such that it is a subsequence
                j++; 
            }
        }
        j = m-1; 
        for (int i = n-1; i >= 0; --i) {
            if (j < 0) break; 
            if (s[i] == t[j]) {
                r[j] = i; 
                //for a suffix of t from j...n-1, i is the smallest 
                //index in s such that it is a subsequence
                j--; 
            }
        }

        int ans = m; 
        for (int i = 0; i < m; ++i) { 
            //update answer for prefix/suffix is removed 
            //only (new t is a prefix or suffix of t)
            if (l[i] != -1) ans = min(ans, m-i-1); 
            if (r[i] != -1) ans = min(ans, i); 
        }

        //if the smallest suffix is invalid, we return our answer
        //in order to avoid annoying casework in our binary search
        if (r[m-1] == -1) return ans; 
        
        for (int i = 0; i < m-1; ++i) {
            if (l[i] != -1) {
                if (l[i] >= r[m-1]) break; 
                
                int lo = i + 1, hi = m - 1; 
                while (lo < hi) {
                    int md = lo + (hi - lo)/2; 
                    //check if left index in s is less than right 
                    //index of the suffix (a < b as said in solution)
                    if (l[i] < r[md]) hi = md; 
                    else lo = md + 1; 
                }
                //lo is the smallest index in the biggest 
                //suffix that satisfies the condition 
                ans = min(ans, lo - i - 1); 
                //lo - i - 1 is the size if the deleted substring
            }
        }
        return ans; 
        
    }
};
