class Solution {
public:
    
    bool check(string& q, vector<string>& dict){
        for(auto d: dict){
            int c = 0;
            for(int i = 0; i < d.size(); ++i){
                if(q[i] != d[i]) c++;
            }
            if(c <= 2) return true;
        }
        return false;
    }
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dict) {
        vector<string> ans;
        for(auto q: queries){
            if(check(q, dict)) ans.push_back(q);
        }
        return ans;
    }
};
