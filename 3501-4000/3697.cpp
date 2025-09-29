class Solution {
public:
    vector<int> decimalRepresentation(int n) {
        vector<int> res;
        long long temp = n;
        long long mul = 1;
        while (temp) {
            int digit = temp % 10;
            if (digit != 0) {
                res.push_back((int)(1LL*digit*mul));
            }
            mul *= 10;
            temp /= 10;
        }
        sort(res.begin(),res.end(),greater<int>());
        return res;
    }
};
