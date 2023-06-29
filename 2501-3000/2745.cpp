class Solution {
public:
    int longestString(int x, int y, int z) {
        int mn = min(x,y);
        if (x == y)
            return (4 * x + z * 2);
        else 
            return (2 * mn + (mn + 1) * 2 + z * 2);
    }
};
