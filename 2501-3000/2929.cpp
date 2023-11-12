class Solution {
public:
    long long distributeCandies(int n, int limit) {
    long long ans = 0;
    int firstMin = max(0, n - 2*limit);
    int firstMax = min(limit, n);
    for(int i = firstMin; i <= firstMax; ++i ){
        int secondMin = max(0, n - i - limit);
        int secondMax = min(limit, n - i);
        ans += secondMax - secondMin + 1;
    }
    return ans;
}
};
