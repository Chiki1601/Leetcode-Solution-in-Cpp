class Solution {
public:
       int countTestedDevices(vector<int>& A) {
        int k = 0;
        for (int a : A)
            k += a > k;
        return k;
    }
};
