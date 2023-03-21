class Solution {
public:
       int findSmallestInteger(vector<int>& A, int k) {
        vector<int> count(k, 0);
        for (int& a : A)
            count[(a % k + k) % k]++;
        int stop = 0;
        for (int i = 0; i < k; ++i)
            if (count[i] < count[stop])
                stop = i;
        return k * count[stop] + stop;
    }
};
