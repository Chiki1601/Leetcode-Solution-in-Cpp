class Solution {
public:
    int minSensors(int n, int m, int k) {
        int side = 2 * k + 1; // coverage in one dimension
        long long rows = (n + side - 1) / side;
        long long cols = (m + side - 1) / side;
        return (int)(rows * cols);
    }
};
