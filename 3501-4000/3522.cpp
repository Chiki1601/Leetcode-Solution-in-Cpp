class Solution {
public:
    long long calculateScore(vector<string>& instructions, vector<int>& values) {
        long long score = 0;
        vector<bool> indices(values.size(), 0);
        for(long long i = 0; i < values.size(); ) {
            if(i < 0 || i >= values.size() || indices[i]) break;
            indices[i] = 1;
            (instructions[i] == "add") ? score += values[i], i++ : i += values[i];
        }
        return score;
    }
};
