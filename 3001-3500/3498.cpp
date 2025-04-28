class Solution {
public:
    int reverseDegree(const std::string& s) {
        int ans = 0, idx = 1;
        for (char ch : s) {
            ans += (123 - static_cast<int>(ch)) * idx;
            idx++;}
        return ans;}
};
