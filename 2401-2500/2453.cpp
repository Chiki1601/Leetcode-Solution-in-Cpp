class Solution {
public:
     int destroyTargets(vector<int>& A, int space) {
        int res = 1e9, maxc = 0;
        unordered_map<int, int> count;
        for (int a : A)
            maxc = max(maxc, ++count[a % space]);
        for (int a : A)
            if (count[a % space] == maxc)
                res = min(res, a);
        return res;
    }
};
