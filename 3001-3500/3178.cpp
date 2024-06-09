class Solution {
public:
    int numberOfChild(int n, int k) {
        int position = 0;
    int direction = 1;
    
    for (int i = 0; i < k; ++i) {
        position += direction;
        
        // Reverse direction if the ball reaches either end
        if (position == n - 1) {
            direction = -1;
        } else if (position == 0) {
            direction = 1;
        }
    }
    
    return position;
    }
};
