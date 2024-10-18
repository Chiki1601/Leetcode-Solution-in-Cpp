class Solution {
public:
    char kthCharacter(int k) {

        int position = std::bitset<32>(k - 1).count();

        return 'a' + position;
    }
};
