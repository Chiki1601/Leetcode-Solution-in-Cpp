class Solution {
public:
    int minimumIndex(std::vector<int>& capacity, int itemSize) {
        int res = std::numeric_limits<int>::max(); 
        int idx = -1; 

        for (int i = 0; i < capacity.size(); ++i) {
            if (itemSize <= capacity[i] && capacity[i] < res) {
                res = capacity[i];
                idx = i;}
        }
        return idx; }
};
    
