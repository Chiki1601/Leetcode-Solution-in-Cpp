class Solution {
public:
    int smallestNumber(int n) {
    return pow(2, ceil(log2(n+1))) - 1;
}
   
};
