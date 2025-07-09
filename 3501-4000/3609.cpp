class Solution {
public:
   int minMoves(int sx, int sy, int tx, int ty) {
    int cnt = 0;
    for (; tx > sx || ty > sy; ++cnt) {
        if (ty > tx) {
            swap(tx, ty);
            swap(sx, sy);
        }
        if (tx == ty) {
            if (sx == 0)
                tx = 0;
            else
                ty = 0;                
        }
        else {
            if (tx < ty * 2)
                tx -= ty;
            else {
                if (tx % 2)
                    return -1;
                tx /= 2;
            }
        }
    }
    return tx < sx || ty < sy ? -1 : cnt;
}
};
