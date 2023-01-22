class Solution {
public:
     bool isReachable(int targetX, int targetY) {
    int g = __gcd(targetX, targetY);
    return (g & (g - 1)) == 0; // check g is power of 2
}
    
};
