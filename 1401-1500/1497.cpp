class Solution {
public:
    bool canArrange(vector<int>& A, int k) {
        unordered_map<int, int> m;
        for (int &n : A) {
            n = (n % k + k) % k;
            m[n]++;
        }
        for (int n : A) {
            if ((n == 0 && m[n] % 2) || (n && m[n] != m[k - n])) return false;
        }
        return true;
    }
};
