class Solution {
public:
   int minImpossibleOR(vector<int>& A) {
        unordered_set<int> s(A.begin(), A.end());
        int a = 1;
        while (s.count(a))
            a <<= 1;
        return a;
    }
};
