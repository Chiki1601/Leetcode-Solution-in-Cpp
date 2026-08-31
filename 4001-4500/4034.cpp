class Solution {
public:
    int minBishopMoves(vector<int>& source, vector<int>& target) {
        int x = source[0], y = source[1];
        int tx = target[0], ty = target[1];

        // Different colors -> impossible
        if ((x + y) % 2 != (tx + ty) % 2)
            return -1;

        // Already at target
        if (x == tx && y == ty)
            return 0;

        // Same diagonal -> one move
        if (abs(x - tx) == abs(y - ty))
            return 1;

        // Same color, but different diagonal -> two moves
        return 2;
    }
};
