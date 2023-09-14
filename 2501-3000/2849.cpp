class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        if(sx == fx && sy == fy){
            return t > 1 || t == 0;
        }
        int height = abs(sy - fy) ;
        int width =  abs(sx - fx) ;
        int time = abs(height - width) ;
        return  (min(height, width) + time)  <= t ;
    }
};
