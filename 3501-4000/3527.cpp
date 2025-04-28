class Solution {
public:
    string findCommonResponse(vector<vector<string>>& responses) {
        string res = "";
        int freq = 0;
        unordered_map<string, int> map;
        for (auto& response : responses){
            unordered_set<string> s;
            for (auto& r : response){
                if (s.insert(r).second){
                    if (++map[r] > freq){
                        freq = map[r];
                        res = r;
                    }
                    else if (map[r] == freq && r < res){
                        res = r;
                    }
                }
            }
        }
        return res;
    }
};
