class Solution {
public:
    int minRange(int a, int b, int c) {
        int highest = max({a, b, c});
        int lowest = min({a, b, c});
        int mid = a + b + c - highest - lowest;
        if (highest >= lowest + mid) {
            return max({lowest + mid, mid, lowest}) - min({lowest + mid, mid, lowest});
        } else {
            return max({highest, mid, lowest}) - min({highest, mid, lowest});
        }
    }
};
