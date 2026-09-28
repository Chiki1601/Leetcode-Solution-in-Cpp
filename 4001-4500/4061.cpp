class Solution {
public:
    int minQueenMoves(vector<int>& source, vector<int>& target) {

        // source = target then 0 moves requires
        if(source[0] == target[0] && source[1] == target[1]) return 0;

        // same row then 1 moves requires
        if(source[0] == target[0]) return 1;

        // same col then 1 moves requires
        if(source[1] == target[1]) return 1;

        // diagonal elements p hai dono source and destination then 1 moves requires
        if(abs(source[0] - target[0]) == abs(source[1] - target[1])) return 1;

        // baaki saare case mai 2 moves mai kaam ho jayega
        return 2;
        
    }
};
