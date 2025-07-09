class Solution {
public:
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        vector<vector<string>> a;
        int n=code.size();

        for(int i=0;i<n;i++){
            if(isActive[i]){
                if(isValid(code[i]) and check(businessLine[i])) a.push_back({businessLine[i],code[i]});
            }
        }
        sort(a.begin(),a.end());
        vector<string> ans;

        for(auto v:a) ans.push_back(v[1]);
        return ans;
    }
private: 
    bool isValid(string s){
        if(s=="") return 0;
        for(auto c:s){
            if((c>='a' and c<='z') or (c>='A' and c<='Z') or (c>='0' and c<='9') or c=='_')
                continue;
            else return 0;
        }
        return 1;
    }
    bool check(string s){
        if(s=="electronics" or s=="grocery" or s=="pharmacy" or s=="restaurant") return 1;
        else return 0;
    }
};
