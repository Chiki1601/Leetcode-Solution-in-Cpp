class Solution {
public:
    
    int maximumValue(vector<string>& strs) {
        int ans = 0;
        for(auto &str: strs) {
            bool onlyCharPresent = true;
            bool onlyIntPresent = true;
            int count = 0;
            for(int i = 0; i < str.size(); i++) {
                if(str[i] - '9' < 0 || str[i]  - '9' == 0) onlyCharPresent = false;
                if(str[i] - 'a' > 0 || str[i]  - 'a' == 0) onlyIntPresent = false;
            }
            if(onlyIntPresent == true) {
                count = stoi(str);
            } 
            if(onlyCharPresent == true) {
                count = str.size();
            }
            if(onlyCharPresent == false and onlyIntPresent == false) count = str.size();
            ans = max(ans, count);
        }
        return ans;
    }
};
